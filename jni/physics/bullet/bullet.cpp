///----------------------------------------------------------------------------------------
/**
 * \file       bullet.cpp
 * \author     Vonasek Lubos
 * \date       2014/12/31
 * \brief      Physical model for scene, it detects collision and also calculate collision
 *             reactions. Also applies car physical and visual state.
**/
///----------------------------------------------------------------------------------------

#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include "engine/switch.h"
#include "physics/bullet/bullet.h"
#include "renderers/opengl/gles20.h"

#define BRAKE_ASPECT 1
#define DYNAMIC_DAMPING 10
#define DYNAMIC_FRICTION 500
#define DYNAMIC_GRAVITATION 10
#define DYNAMIC_ROLLING_FRICTION 0
#define ENGINE_MAX_SPEED 300
#define GAS_ASPECT 0.00005
#define GRAVITATION 10
#define OVERSPEED_BRAKING 0.2
#define ROLL_INFLUENCE 0.001
#define SKIN_FRICTION 5
#define SPEED_DECREASE 50
#define STEERING_ASPECT 45
#define STEERING_SPEED_DEPENDENCY 2.5
#define SUSPENSION_COMPRESSION 0.001
#define SUSPENSION_DAMPING 0.001
#define SUSPENSION_REST_LENGTH 0.45
#define SUSPENSION_STIFFNESS 0.02
#define UNDERSPEED_BRAKING 400
#define VEHICLE_MASS_ASPECT 2
#define VEHICLE_STEP 100
#define WHEEL_FRICTION 300
#define WORLD_LIMIT 50
#define WORLD_STEP 100
#define WORLD_SUBSTEP 4

/**
 * @brief bullet destructor
 */
bullet::~bullet() {
    delete m_dynamicsWorld;
    while(!m_vehicle.empty())
    {
        delete m_vehicle[m_vehicle.size() - 1];
        m_vehicle.pop_back();
    }
    while(!bodies.empty())
    {
        delete bodies[bodies.size() - 1];
        bodies.pop_back();
    }
    while(!shapes.empty())
    {
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
    }
    while(!meshes.empty())
    {
        delete meshes[meshes.size() - 1];
        meshes.pop_back();
    }
    while(!bodies2.empty())
    {
        delete bodies2[bodies2.size() - 1];
        bodies2.pop_back();
    }

    delete m_vehicleRayCaster;
    delete m_collisionConfiguration;
    delete m_dispatcher;
    delete m_overlappingPairCache;
    delete m_constraintSolver;
#ifndef ANDROID
    delete m_shapeDrawer;
#endif
}

/**
 * @brief Construct physical model
 */
bullet::bullet() {

    /// init engine
    active = true;
    locked = true;
    m_collisionConfiguration = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
    btVector3 worldMin(-WORLD_LIMIT,-WORLD_LIMIT,-WORLD_LIMIT);
    btVector3 worldMax(WORLD_LIMIT,WORLD_LIMIT,WORLD_LIMIT);
    m_overlappingPairCache = new btAxisSweep3(worldMin,worldMax);
    m_constraintSolver = new btSequentialImpulseConstraintSolver();
    m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher,m_overlappingPairCache,m_constraintSolver,m_collisionConfiguration);
    m_dynamicsWorld->setGravity(btVector3(0,-GRAVITATION,0));
    m_vehicleRayCaster = new btDefaultVehicleRaycaster(m_dynamicsWorld);

#ifndef ANDROID
    /// set bullet debugging renderer
    m_shapeDrawer = new GL_ShapeDrawer();
    m_shapeDrawer->enableTexture(true);

    GLfloat light_ambient[] = { btScalar(0.2), btScalar(0.2), btScalar(0.2), btScalar(1.0) };
    GLfloat light_diffuse[] = { btScalar(1.0), btScalar(1.0), btScalar(1.0), btScalar(1.0) };
    GLfloat light_specular[] = { btScalar(1.0), btScalar(1.0), btScalar(1.0), btScalar(1.0 )};
    GLfloat light_position0[] = { btScalar(1.0), btScalar(10.0), btScalar(1.0), btScalar(0.0 )};
    GLfloat light_position1[] = { btScalar(-1.0), btScalar(-10.0), btScalar(-1.0), btScalar(0.0) };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(btScalar(0.7),btScalar(0.7),btScalar(0.7),btScalar(0));
#endif
}

/**
 * @brief addCar adds car into physical model
 * @param c is car instance
 */
void bullet::addCar(car* c) {

    /// set chassis
    float width = c->skin->aabb.max.x - c->skin->aabb.min.x;
    float altitude = c->skin->aabb.max.y - c->skin->aabb.min.y;
    float height = c->skin->aabb.max.z - c->skin->aabb.min.z;
    btCollisionShape* chassisShape = new btBoxShape(btVector3(width / 2.0f, altitude / 2.0f, height / 2.0f));
    shapes.push_back(chassisShape);
    btCompoundShape* compound = new btCompoundShape();
    shapes.push_back(compound);
    btTransform localTrans;
    localTrans.setIdentity();
    localTrans.setOrigin(btVector3(0, c->wheelY, 0));
    compound->addChildShape(localTrans,chassisShape);

    /// Set car physical values
    btVector3 localInertia(0,0,0);
    float mass = VEHICLE_MASS_ASPECT * c->mass;
    compound->calculateLocalInertia(mass,localInertia);
    btRigidBody* m_carChassis = new btRigidBody(mass,0,compound,localInertia);
    bodies2.push_back(m_carChassis);
    m_dynamicsWorld->addRigidBody(m_carChassis);

    /// Set car default transform
    btTransform tr;
    tr.setIdentity();
    tr.setOrigin(btVector3(c->pos.x, c->pos.y + 2, c->pos.z));
    btQuaternion qn;
    qn.setW(btScalar(cos(c->rot * 3.14 / 180 / 2.0f)));
    qn.setX(btScalar(0));
    qn.setY(btScalar(sin(c->rot * 3.14 / 180 / 2.0f)));
    qn.setZ(btScalar(0));
    tr.setRotation(qn);

    /// Create car
    m_carChassis->setCenterOfMassTransform(tr);
    btRaycastVehicle::btVehicleTuning m_tuning;
    btRaycastVehicle *m_RaycastVehicle = new btRaycastVehicle(m_tuning,m_carChassis,m_vehicleRayCaster);
    m_vehicle.push_back(m_RaycastVehicle);
    m_carChassis->setActivationState(DISABLE_DEACTIVATION);
    m_dynamicsWorld->addVehicle(m_vehicle[c->index - 1]);
    m_vehicle[c->index - 1]->setCoordinateSystem(0,1,2);

    /// Set wheels connections
    altitude = (c->wheel->aabb.max.y - c->wheel->aabb.min.y) / 2.0f;
    btVector3 direction(0,-1,0);
    btVector3 axle(-1,0,0);
    btVector3 point(-c->wheelX, 0, -c->wheelZ1);
    m_vehicle[c->index - 1]->addWheel(point, direction, axle, SUSPENSION_REST_LENGTH, altitude, m_tuning, true);
    point = btVector3(c->wheelX, 0, -c->wheelZ1);
    m_vehicle[c->index - 1]->addWheel(point, direction, axle, SUSPENSION_REST_LENGTH, altitude, m_tuning, true);
    point = btVector3(-c->wheelX, 0, c->wheelZ2);
    m_vehicle[c->index - 1]->addWheel(point, direction, axle, SUSPENSION_REST_LENGTH, altitude, m_tuning, false);
    point = btVector3(c->wheelX, 0, c->wheelZ2);
    m_vehicle[c->index - 1]->addWheel(point, direction, axle, SUSPENSION_REST_LENGTH, altitude, m_tuning, false);

    /// Set wheels parameters
    for (int i = 0; i < m_vehicle[c->index - 1]->getNumWheels(); i++) {
        btWheelInfo& wheel = m_vehicle[c->index - 1]->getWheelInfo(i);
        wheel.m_suspensionStiffness = SUSPENSION_STIFFNESS;
        wheel.m_wheelsDampingRelaxation = SUSPENSION_DAMPING;
        wheel.m_wheelsDampingCompression = SUSPENSION_COMPRESSION;
        wheel.m_frictionSlip = WHEEL_FRICTION;
        wheel.m_rollInfluence = ROLL_INFLUENCE;
    }
}

void bullet::addHeightmap(unsigned char* data, int res, glm::vec3 min, glm::vec3 max) {

    btHeightfieldTerrainShape* shape = new btHeightfieldTerrainShape(res, res, data, 1,
                                                           0, 255, 1, PHY_UCHAR, false);
    shape->setLocalScaling(btVector3((max.x - min.x) / (float)res,
                                     (max.y - min.y) / 255.0f,
                                     (max.z - min.z) / (float)res));
    shapes.push_back(shape);
    btRigidBody* body = new btRigidBody(0,0,shape);
    body->translate(btVector3((max.x + min.x) / 2.0f,
                              (max.y + min.y) / 2.0f,
                              (max.z + min.z) / 2.0f));
    body->setActivationState(DISABLE_SIMULATION);
    bodies2.push_back(body);
    m_dynamicsWorld->addCollisionObject(body);
}

/**
 * @brief addModel adds model into physical model
 * @param m is 3D model for physical model
 * @param center is model translation
 */
void bullet::addModel(model *m) {
    btTriangleMesh* mesh = new btTriangleMesh();
    bool touchable = false;
    int count = 0;
    for (unsigned int i = 0; i < m->models.size(); i++) {
      if (m->models[i].touchable)
          touchable = true;
    }
    for (unsigned int i = 0; i < m->models.size(); i++) {
        if (m->models[i].dynamic) {

            /// Create object
            float w = m->models[i].reg.max.x - m->models[i].reg.min.x;
            float a = m->models[i].reg.max.y - m->models[i].reg.min.y;
            float h = m->models[i].reg.max.z - m->models[i].reg.min.z;
            btBoxShape* shape = new btBoxShape(btVector3(w / 2, a / 2, h / 2));
            shapes.push_back(shape);

            /// Set object physical values
            btVector3 localInertia(0, 0, 0);
            shape->calculateLocalInertia(w * a * h,localInertia);
            btRigidBody* body = new btRigidBody(w * a * h + 1, 0, shape,localInertia);
            bodies.push_back(body);
            m_dynamicsWorld->addRigidBody(body);

            /// Set object default transform
            btTransform tr;
            tr.setIdentity();
            tr.setOrigin(btVector3(m->models[i].reg.min.x + w / 2,
                                   m->models[i].reg.min.y + a / 2,
                                   m->models[i].reg.min.z + h / 2));

            /// Create object
            body->setCenterOfMassTransform(tr);
            body->setFriction(DYNAMIC_FRICTION);
            body->setRollingFriction(DYNAMIC_ROLLING_FRICTION);
            body->setDamping(DYNAMIC_DAMPING, DYNAMIC_DAMPING);
            body->setGravity(btVector3(0, -GRAVITATION * DYNAMIC_GRAVITATION, 0));
            body->setActivationState(ISLAND_SLEEPING);
            m->models[i].dynamicID = bodies.size();
        } else if (m->models[i].touchable || !touchable) {
            btVector3 o = btVector3(m->models[i].reg.min.x, m->models[i].reg.min.y, m->models[i].reg.min.z);
            for (int j = 0; j < m->models[i].vertices.size() / 9; j++) {
                btVector3 a = btVector3(m->models[i].vertices[j * 9 + 0], m->models[i].vertices[j * 9 + 1], m->models[i].vertices[j * 9 + 2]);
                btVector3 b = btVector3(m->models[i].vertices[j * 9 + 3], m->models[i].vertices[j * 9 + 4], m->models[i].vertices[j * 9 + 5]);
                btVector3 c = btVector3(m->models[i].vertices[j * 9 + 6], m->models[i].vertices[j * 9 + 7], m->models[i].vertices[j * 9 + 8]);
                mesh->addTriangle(a + o, b + o, c + o);
                count++;
                if (count >= 65535)
                {
                    count = 0;
                    meshes.push_back(mesh);
                    btBvhTriangleMeshShape* levelShape = new btBvhTriangleMeshShape(mesh,true);
                    shapes.push_back(levelShape);
                    btRigidBody* body = new btRigidBody(0,0,levelShape);
                    body->setActivationState(DISABLE_SIMULATION);
                    bodies2.push_back(body);
                    m_dynamicsWorld->addCollisionObject(body);
                    mesh = new btTriangleMesh();
                }
            }
        }
    }
    if (count > 0) {
        meshes.push_back(mesh);
        btBvhTriangleMeshShape* levelShape = new btBvhTriangleMeshShape(mesh,true);
        shapes.push_back(levelShape);
        btRigidBody* body = new btRigidBody(0,0,levelShape);
        body->setActivationState(DISABLE_SIMULATION);
        bodies2.push_back(body);
        m_dynamicsWorld->addCollisionObject(body);
    } else
        delete mesh;
}

/**
 * @brief getTransform counts OpenGL matrix of transformation
 * @param index is index of object
 * @return transformation matrix
 */
void bullet::getTransform(int index, float* m) {

    /// get matrix
    bodies[index - 1]->getCenterOfMassTransform().getOpenGLMatrix(m);
    for (int i = 0; i < 16; i++) {
        if (isnan(m[i])) {
            for (int j = 0; j < 16; j++)
                m[j] = (j % 5 == 0) ? 1 : 0;
            return;
        }
    }
}

void bullet::render() {
#ifndef ANDROID
    btScalar	m[16];
    btMatrix3x3	rot;rot.setIdentity();
    const int	numObjects=m_dynamicsWorld->getNumCollisionObjects();
    btVector3 wireColor(1,0,0);
    for(int i=0;i<numObjects;i++) {
        btCollisionObject*	colObj=m_dynamicsWorld->getCollisionObjectArray()[i];
        btRigidBody*		body=btRigidBody::upcast(colObj);
        if(body&&body->getMotionState()) {
            btDefaultMotionState* myMotionState = (btDefaultMotionState*)body->getMotionState();
            myMotionState->m_graphicsWorldTrans.getOpenGLMatrix(m);
            rot=myMotionState->m_graphicsWorldTrans.getBasis();
        }
        else
        {
            colObj->getWorldTransform().getOpenGLMatrix(m);
            rot=colObj->getWorldTransform().getBasis();
        }
        btVector3 wireColor(0, 1, 0); //wants deactivation
        ///color differently for active, sleeping, wantsdeactivation states
        switch(colObj->getActivationState()) {
        case(ACTIVE_TAG):
            wireColor = btVector3 (1, 0, 0);
            break;
        case(ISLAND_SLEEPING):
            wireColor = btVector3 (0, 0, 1);
            break;
        case(WANTS_DEACTIVATION):
            wireColor = btVector3 (0, 1, 0);
            break;
        case(DISABLE_DEACTIVATION):
            wireColor = btVector3 (1, 1, 0);
            break;
        case(DISABLE_SIMULATION):
            wireColor = btVector3 (0.5f, 0.5f, 0.5f);
            break;
        }

        btVector3 aabbMin(0,0,0),aabbMax(0,0,0);
        aabbMin-=btVector3(BT_LARGE_FLOAT,BT_LARGE_FLOAT,BT_LARGE_FLOAT);
        aabbMax+=btVector3(BT_LARGE_FLOAT,BT_LARGE_FLOAT,BT_LARGE_FLOAT);
        m_shapeDrawer->drawOpenGL(m,colObj->getCollisionShape(),wireColor,0,aabbMin,aabbMax);
        m_shapeDrawer->drawOpenGL(m,colObj->getCollisionShape(),wireColor,1,aabbMin,aabbMax);
    }
#endif
}

/**
 * @brief resetCar updates car state
 * @param c is instance of car
 */
void bullet::resetCar(car* c) {
    c->resetRequested = false;
    c->setStart(c->currentEdge, 0);
    btTransform tr;
    tr.setIdentity();
    tr.setOrigin(btVector3(c->pos.x,c->pos.y + 2,c->pos.z));
    btQuaternion q;
    q.setRotation(btVector3(0,1,0), c->rot * 3.14 / 180.0);
    tr.setRotation(q);
    m_vehicle[c->index - 1]->getRigidBody()->setCenterOfMassTransform(tr);
}

/**
 * @brief updateCar updates car state
 * @param c is instance of car
 */
void bullet::updateCar(car* c) {

    /// get direction
    if ((int)m_vehicle[c->index - 1]->getCurrentSpeedKmHour() < 0)
        c->reverse = true;
    if ((int)m_vehicle[c->index - 1]->getCurrentSpeedKmHour() > 0)
        c->reverse = false;

    if (fabsf(m_vehicle[c->index - 1]->getCurrentSpeedKmHour()) < 5) {
        if (c->control->getGas() > 0)
            c->reverse = false;
        if (c->control->getBrake() > 0)
            c->reverse = true;
    }

    /// Set power
    float acc = c->acceleration;
    float max = c->gears[c->currentGear].max;
    if (c->n2o < 150) {
        c->n2o += 0.1f;
    }
    if (c->control->getNitro()) {
        if (c->n2o >= 1) {
            acc *= 2;
            max *= 1.5f;
            c->n2o--;
        }
    }

    /// set forces
    float gEngineForce = c->control->getGas() * (ENGINE_MAX_SPEED - c->speed) * acc * GAS_ASPECT;
    float gBreakingForce = c->control->getBrake() * c->brakePower * BRAKE_ASPECT;
    if (c->reverse) {
        gEngineForce = c->control->getBrake() * (ENGINE_MAX_SPEED - c->speed) * acc * GAS_ASPECT;
        gBreakingForce = c->control->getGas() * c->brakePower * BRAKE_ASPECT / 2.0;
    }

    /// set auto braking
    if (c->speed < c->gears[c->currentGear].min) {
        gEngineForce = 0;
        gBreakingForce = UNDERSPEED_BRAKING;
    }

    /// Limit power
    if (max < c->speed) {
        gEngineForce = 0;
        gBreakingForce = OVERSPEED_BRAKING;
    }

    /// Apply power
    if (!locked) {
        float gVehicleSteering = c->control->getSteer() * c->steering;
            gVehicleSteering /= (STEERING_ASPECT + c->speed * STEERING_SPEED_DEPENDENCY);

        m_vehicle[c->index - 1]->setSteeringValue(gVehicleSteering,2);
        m_vehicle[c->index - 1]->setSteeringValue(gVehicleSteering,3);

        if (c->reverse) {
            m_vehicle[c->index - 1]->applyEngineForce(-gEngineForce,0);
            m_vehicle[c->index - 1]->applyEngineForce(-gEngineForce,1);
        } else {
            m_vehicle[c->index - 1]->applyEngineForce(gEngineForce,0);
            m_vehicle[c->index - 1]->applyEngineForce(gEngineForce,1);
        }
    }
    m_vehicle[c->index - 1]->setBrake(gBreakingForce + SPEED_DECREASE, 0);
    m_vehicle[c->index - 1]->setBrake(gBreakingForce + SPEED_DECREASE, 1);

    for (int i = 0; i < 4; i++)
        m_vehicle[c->index - 1]->updateWheelTransform(i);

    /// Apply updates
    m_vehicle[c->index - 1]->updateVehicle(VEHICLE_STEP);

    /// Reset car
    if ((c->speed < 5) && active && !locked) {
        if (c->onRoof > 60) {
            c->resetAllowed = true;
            if ((int)c->index - 1 != 0) {
                c->resetRequested = true;
            }
            c->onRoof = 0;
        } else if (c->speed < 5) {
            c->onRoof++;
        }
    } else {
        c->resetAllowed = false;
    }

    // reset car
    if (c->resetAllowed && c->resetRequested) {
        for (unsigned int i = 0; i < getCarCount(); i++) {
            if (i != c->index - 1) {
                if (glm::length(c->currentEdge.a - getCar(i)->pos) < 10) {
                    return;
                }
            }
        }
        resetCar(c);
    }


    /// count angle
    btQuaternion qn = m_vehicle[c->index - 1]->getRigidBody()->getOrientation();
    float rot = getRotation(qn.x(),qn.y(),qn.z(),qn.w());
    if (!isnan(rot)) {
        c->rot=rot;
    }

    /// get position
    float x = m_vehicle[c->index - 1]->getRigidBody()->getCenterOfMassPosition().getX();
    float y = m_vehicle[c->index - 1]->getRigidBody()->getCenterOfMassPosition().getY();
    float z = m_vehicle[c->index - 1]->getRigidBody()->getCenterOfMassPosition().getZ();
    if (!isnan(x) && !isnan(y) && !isnan(z)) {
        c->pos.x=x;
        c->pos.y=y;
        c->pos.z=z;
    }

    /// get matrices
    for (int index = 0; index < 5; index++) {
        if (index > 0) {
          m_vehicle[c->index - 1]->getWheelInfo(index - 1).m_worldTransform.getOpenGLMatrix(c->transform[index].value);
        } else {
          m_vehicle[c->index - 1]->getRigidBody()->getCenterOfMassTransform().getOpenGLMatrix(c->transform[index].value);
        }
    }
}

/**
 * @brief updateWorld updates world state
 */
void bullet::updateWorld() {
     m_dynamicsWorld->stepSimulation(WORLD_STEP, WORLD_SUBSTEP);
}
