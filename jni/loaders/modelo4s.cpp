//----------------------------------------------------------------------------------------
/**
 * \file       modelo4s.cpp
 * \author     Vonasek Lubos
 * \date       2014/02/23
 * \brief      Class for loading models into OpenGL list, it parse full model file, apply
 *             textures, materials and blending.
*/
//----------------------------------------------------------------------------------------

#include "loaders/modelo4s.h"
#include "utils/io.h"
#include "utils/math.h"
#include "utils/switch.h"
#include "common.h"

char* line = new char[1024];

/**
 * @brief Constructor for loading model from file
 * @param filename is path and name of file to load
 */
modelo4s::modelo4s(const char* filename) {

    /// open file
#ifdef ZIP_ARCHIVE
    zip_file* file = zip_fopen(APKArchive, prefix(filename), 0);
#else
    FILE* file = fopen(prefix(filename), "r");
#endif

    /// get model dimensions
    gets(line, file);
    cutX = scandec(line);
    gets(line, file);
    cutY = scandec(line);
    gets(line, file);
    sscanf(line, "%f %f %f %f %f %f", &aabb.min.x, &aabb.min.y, &aabb.min.z, &aabb.max.x, &aabb.max.y, &aabb.max.z);
    width = aabb.max.x - aabb.min.x;
    aplitude = aabb.max.y - aabb.min.y;
    height = aabb.max.z - aabb.min.z;

    /// get amount of textures in model
    gets(line, file);
    int textureCount = scandec(line);

    /// parse all textures
    for (int i = 0; i < textureCount; i++) {

        /// set default value
        model3d *m = new model3d();
        m->reg = new AABB();
        m->triangleCount = new int[cutX * cutY + 1];
        float *colora = new float[4];
        float *colord = new float[4];
        float *colors = new float[4];
        colora[3] = 1;
        colord[3] = 1;
        colors[3] = 1;

        /// get material attributes
        float alpha = 1;
        char texturePath[255];
        char material[255];
        material[0] = '\0';
        gets(line, file);
        sscanf(line, "%f %f %f %f %f %f %s %f %f %f %f %f %f %f %f %f %f %s",
               &m->reg->min.x, &m->reg->min.y, &m->reg->min.z, &m->reg->max.x, &m->reg->max.y, &m->reg->max.z,
               &texturePath[0], &colora[0], &colora[1], &colora[2], &colord[0], &colord[1], &colord[2],
               &colors[0], &colors[1], &colors[2], &alpha, &material[0]);

        /// get model size
        m->x = m->reg->min.x;
        m->y = m->reg->min.y;
        m->z = m->reg->min.z;

        /// if texture is not only single color then load it
        if (texturePath[0] != '*') {
            m->texture2D = getTexture(texturePath, alpha);
        /// create color texture
        } else {
            m->texture2D = getTexture(colord[0], colord[1], colord[2], alpha);
        }

        int cursor = 0;
        m->dynamic = false;
        m->filter = 0;
        m->touchable = true;
        if (m->texture2D->transparent) {
            m->material = getShader("standart_alpha");
        } else {
            m->material = getShader("standart");
        }

        /// get material parameters
        while(true) {
            if (material[cursor] == '!') {
                m->touchable = false;
                cursor++;
            } else if (material[cursor] == '$') {
                m->dynamic = true;
                cursor++;
            } else if (material[cursor] == '#') {
                cursor++;
                m->filter = material[cursor] - '0';
                cursor++;
            } else if (material[cursor] == '%') {
                cursor++;
                m->texture2D->transparent = false;
                char* shadername = new char[strlen(material) - cursor + 1];
                for (unsigned int j = cursor; j < strlen(material); j++) {
                    shadername[j - cursor] = material[j];
                    if (material[j] == '/') {
                        shadername[j - cursor] = '\000';
                        break;
                    }
                }
                shadername[strlen(material) - cursor] = '\000';
                m->material = getShader(shadername);
                break;
            } else {
                break;
            }
        }

        /// prepare model arrays
        m->triangleCount[0] = 0;
        for (int j = 1; j <= cutX * cutY; j++) {
            gets(line, file);
            m->triangleCount[j] = scandec(line);
        }
        m->vertices = new float[m->triangleCount[cutX * cutY] * 3 * 3];
        m->normals = new float[m->triangleCount[cutX * cutY] * 3 * 3];
        m->coords = new float[m->triangleCount[cutX * cutY] * 3 * 2];
        m->colora = colora;
        m->colord = colord;
        m->colors = colors;
        for (int j = 0; j < m->triangleCount[cutX * cutY]; j++) {
            /// read triangle parameters
            gets(line, file);
            sscanf(line, "%f %f %f %f %f %f %f %f%f %f %f %f %f %f %f %f%f %f %f %f %f %f %f %f",
                   &m->coords[j * 3 * 2 + 0], &m->coords[j * 3 * 2 + 1],
                   &m->normals[j * 3 * 3 + 0], &m->normals[j * 3 * 3 + 1], &m->normals[j * 3 * 3 + 2],
                   &m->vertices[j * 3 * 3 + 0], &m->vertices[j * 3 * 3 + 1], &m->vertices[j * 3 * 3 + 2],
                   &m->coords[j * 3 * 2 + 2], &m->coords[j * 3 * 2 + 3],
                   &m->normals[j * 3 * 3 + 3], &m->normals[j * 3 * 3 + 4], &m->normals[j * 3 * 3 + 5],
                   &m->vertices[j * 3 * 3 + 3], &m->vertices[j * 3 * 3 + 4], &m->vertices[j * 3 * 3 + 5],
                   &m->coords[j * 3 * 2 + 4], &m->coords[j * 3 * 2 + 5],
                   &m->normals[j * 3 * 3 + 6], &m->normals[j * 3 * 3 + 7], &m->normals[j * 3 * 3 + 8],
                   &m->vertices[j * 3 * 3 + 6], &m->vertices[j * 3 * 3 + 7], &m->vertices[j * 3 * 3 + 8]);
        }

        /// store model in VBO
        int size = sizeof(float)*m->triangleCount[cutX * cutY] * 3;
            m->vboData = getVBO(size, m->vertices, m->normals, m->coords);
        models.push_back(*m);
    }

    /// load edges
    gets(line, file);
    edgesCount = scandec(line);
    edges = new std::vector<edge>[edgesCount];
    for (int i = 0; i < edgesCount; i++) {
        gets(line, file);
        int edgeCount = scandec(line);
        for (int j = 0; j < edgeCount; j++) {
            edge value;
            gets(line, file);
            sscanf(line, "%f %f %f %f %f %f", &value.ax, &value.ay, &value.az, &value.bx, &value.by, &value.bz);
            edges[i].push_back(value);
        }
        for (int j = 0; j < edgeCount; j++) {
            edge value;
            value.ax = edges[i][j].bx;
            value.ay = edges[i][j].by;
            value.az = edges[i][j].bz;
            value.bx = edges[i][j].ax;
            value.by = edges[i][j].ay;
            value.bz = edges[i][j].az;
            edges[i].push_back(value);
        }
    }

#ifdef ZIP_ARCHIVE
    zip_fclose(file);
#else
    fclose(file);
#endif
}
