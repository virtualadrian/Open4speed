///----------------------------------------------------------------------------------------
/**
 * \file       glvbo.h
 * \author     Vonasek Lubos
 * \date       2014/12/30
 * \brief      Vertex buffer object for OpenGL
**/
///----------------------------------------------------------------------------------------

#ifndef GLVBO_H
#define GLVBO_H

#include "interfaces/vbo.h"

class glvbo : public vbo
{
public:

    unsigned int instance;         ///< VBO for current object
    int size;

    /**
     * @brief removes all data from memory
     */
    ~glvbo();

    /**
     * @brief glvbo creates VBO from data
     * @param size is amount of vertices
     * @param vertices is vertices array
     * @param normals is normals array
     * @param coords is texture coords array
     */
    glvbo(int size, float* vertices, float* normals, float* coords);

    /**
     * @brief render renders vbo
     * @param sh is shader for rendering
     * @param begin is index of first vector/triangle
     * @param len is length of data to renderer
     */
    void render(shader* sh, int begin, int len);

    /**
     * @brief update updates VBO data
     * @param size is amount of vertices
     * @param vertices is vertices array
     * @param normals is normals array
     * @param coords is texture coords array
     */
    void update(int size, float* vertices, float* normals, float* coords);
};

#endif // GLVBO_H
