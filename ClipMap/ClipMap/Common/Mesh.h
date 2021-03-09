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
#include <glm/gtc/matrix_transform.hpp>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
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
