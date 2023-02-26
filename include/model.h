#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"

struct vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    aiString path;
};

class Mesh{
public:
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> texture;

    Mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> texture);
    void Draw(Shader & shader);

private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

class Model{
public:
    Model(const std::string& modelPath, const std::string& texturePath);
    void Draw(Shader& shader);

private:
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;
    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

#endif