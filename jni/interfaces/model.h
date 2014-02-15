//----------------------------------------------------------------------------------------
/**
 * \file       model.h
 * \author     Vonasek Lubos
 * \date       2014/01/05
 * \brief      Loading and storing models
*/
//----------------------------------------------------------------------------------------

#ifndef MODEL_H
#define MODEL_H

#include "interfaces/fbo.h"
#include "interfaces/shader.h"
#include "interfaces/texture.h"
#include "interfaces/vbo.h"
#include "loaders/dynamiclight.h"

/**
 * @brief The edge struct
 */
struct edge {
    float ax;    ///< Point coordinate
    float ay;    ///< Point coordinate
    float az;    ///< Point coordinate
    float bx;    ///< Point coordinate
    float by;    ///< Point coordinate
    float bz;    ///< Point coordinate
};

/**
 * @brief The region struct
 */
struct region {
    float minX; ///< Region extreme
    float minY; ///< Region extreme
    float minZ; ///< Region extreme
    float maxX; ///< Region extreme
    float maxY; ///< Region extreme
    float maxZ; ///< Region extreme
    float size; ///< Region size
};

/**
 * @brief The model3d struct
 */
struct model3d {
    bool touchable;     ///< info if it is used in physics
    bool usingLightmaps;///< info if lightmap is used
    int filter;         ///< filter index
    shader* material;   ///< shader to use
    float *colora;      ///< Ambient color
    float *colord;      ///< Diffuse color
    float *colors;      ///< Specular color
    bool dynamic;       ///< True if object is dynamic
    int dynamicID;      ///< ID of the last dynamic update
    int lmIndex;        ///< index of lightmap
    region *reg;        ///< AABB of the object
    int* triangleCount; ///< Amount of triangles
    texture* texture2D; ///< Object texture
    float* vertices;    ///< Object vertices
    float* normals;     ///< Object normals
    float* coords;      ///< Object texture coordinates
    float* tid;         ///< Object lightmap coordinates
    float x,y,z;        ///< Object translation
    vbo* vboData;       ///< VBO of model
};

/**
 * @brief The model interface
 */
class model {
public:

    /**
     * @brief model destructor
     */
    virtual ~model() = 0;

    int cutX, cutY, edgesCount;                ///< Size of SS Culling
    std::vector<edge> *edges;                  ///< All standalone edges of model
    std::vector<model3d> models;               ///< All parts of model
    float minx, miny, minz, maxx, maxy, maxz;  ///< Extremes of current model
    float width, aplitude, height, size;       ///< Dimensions of current model
    std::vector<fbo*> lightmaps;               ///< List of lightmaps
    DynamicLight *dynamicLight;                ///< Dynamic lights in lightmaps

    /**
     * @brief getLMCount get amount of lightmaps
     * @return lightmaps count
     */
    virtual int getLMCount() = 0;
};

#endif // MODEL_H
