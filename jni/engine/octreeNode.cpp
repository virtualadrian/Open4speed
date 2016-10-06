//----------------------------------------------------------------------------------------
/**
 * \file       octreeNode.cpp
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Class for render optimalization using octree
*/
//----------------------------------------------------------------------------------------

#include "engine/octreeNode.h"

float dst;       ///< far from glperspective
glm::mat4x4 mvp; ///< model view matrix(camera)
glm::vec3 min;   ///< AABB corner of current node
glm::vec3 max;   ///< AABB corner of current node

//TODO:octree building

/**
 * @brief getTransform gets position of AABB vertex in frustum space
 * @param i is index of vertex
 * @return transformed vertex in frustum space
 */
glm::vec4 octreeNode::getTransform(int i) {
    glm::vec4 position;
    switch(i)
    {
    case(0):
        position = mvp * glm::vec4(min.x, min.y, min.z, 1);
        break;
    case(1):
        position = mvp * glm::vec4(min.x, min.y, max.z, 1);
        break;
    case(2):
        position = mvp * glm::vec4(min.x, max.y, min.z, 1);
        break;
    case(3):
        position = mvp * glm::vec4(min.x, max.y, max.z, 1);
        break;
    case(4):
        position = mvp * glm::vec4(max.x, min.y, min.z, 1);
        break;
    case(5):
        position = mvp * glm::vec4(max.x, min.y, max.z, 1);
        break;
    case(6):
        position = mvp * glm::vec4(max.x, max.y, min.z, 1);
        break;
    case(7):
        position = mvp * glm::vec4(max.x, max.y, max.z, 1);
        break;
    }

    position.x = position.x / position.w;
    position.y = position.y / position.w;
    position.z = position.z / dst * 2.0f - 1.0f;
    return position;
}

/**
 * @brief process processes node and subnodes
 */
void octreeNode::process() {

    // TODO:add all voxels in node

    /// Basic Intersection Test
    int x1 = 0; int x2 = 0; int y1 = 0; int y2 = 0; int z1 = 0; int z2 = 0;
    for (int i = 0; i < 8; i++) {
        /// check if it is inside
        glm::vec4 vec = getTransform(i);
        if (vec.x <= 1) { x1++; }
        if (vec.x >= -1) { x2++; }
        if (vec.y <= 1) { y1++; }
        if (vec.y >= -1) { y2++; }
        if (vec.z <= 1) { z1++; }
        if (vec.z >= -1) { z2++; }
    }

    /// return value
    if (x1 + y1 + x2 + y2 + z1 + z2 == 48)
        processAll();
    else if ((x1 > 0) && (x2 > 0) && (y1 > 0) && (y2 > 0) && (z1 > 0) && (z2 > 0))
        for (int i = 0; i < 8; i++)
            if (next[i])
            {
                // TODO:update min, max
                next[i]->process();
            }
}

/**
 * @brief processAll adds all into to render list
 */
void octreeNode::processAll() {
    // TODO:add all voxels in node
    for (int i = 0; i < 8; i++) {
        if (next[i]) {
            // TODO:update min, max
            next[i]->processAll();
        }
    }
}

//TODO:getting culled data from octree
