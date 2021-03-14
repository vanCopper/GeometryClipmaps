#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
//GL includes
#include <GL/glew.h>
#include <glm/glm.hpp>


struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;

    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texcoords)
    {
        Position = position;
        Normal = normal;
        TexCoords = texcoords;
    }
};

struct Texture
{
    GLuint Id;
    string Type;
    string Path;
};

class Mesh
{
public:
    vector<Vertex> vertices;
    vector<GLuint> indices;
    vector<Texture> textures;

    Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
    Mesh(vector<Vertex> vertices, vector<GLuint> indices);

    void Draw(GLuint shaderProgramID);

private:
    //vertex array object, vertex buffer object, element buffer object
    GLuint VAO, VBO, EBO;

    void SetupMesh();
};

