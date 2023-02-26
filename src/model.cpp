#include "model.h"

Mesh::Mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> texture) {
    setupMesh();
}

void Mesh::Draw(Shader& shader){
    unsigned int diffuseNR = 1;
    unsigned int specularNr = 1;

    for(unsigned int i = 0; i < texture.size(); i++){
        glActiveTexture(GL_TEXTURE + i); // activate proper texture unit before binding
        //retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = texture[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNR++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++);

        shader.setInt(("material." + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, texture[i].id);
    }

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glActiveTexture(GL_TEXTURE);
}

void Mesh::setupMesh() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*) 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, Normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, TexCoords));

    glBindVertexArray(0);
}

Model::Model(const std::string& modelPath, const std::string& texturePath){
    loadModel(modelPath);

    for(unsigned int i = 0; i < textures_loaded.size(); i++){
        Texture texture = textures_loaded[i];
        texture.path = texturePath + texture.path.C_Str();
        textures_loaded[i] = texture;
    }
}

void Model::Draw(Shader& shader){
    for(unsigned int i = 0; i < meshes.size(); i++){
        meshes[i].Draw(shader);
    }
}

void Model::loadModel(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++){
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++){
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    // process vertices
    for(unsigned int i = 0; i < mesh->mNumVertices; i++){
        vertex vertex;
        // process vertex positions, normals and texture coordinates
        glm::vec3 position;
        position.x = mesh->mVertices[i].x;
        position.y = mesh->mVertices[i].y;
        position.z = mesh->mVertices[i].z;
        vertex.Position = position;

        glm::vec3 normal;
        normal.x = mesh->mNormals[i].x;
        normal.y = mesh->mNormals[i].y;
        normal.y = mesh->mNormals[i].z;
        vertex.Normal = normal;

        if(mesh->mTextureCoords[0]){
            glm::vec2 texCoords;
            texCoords.x = mesh->mTextureCoords[0][i].x;
            texCoords.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = texCoords;
        }
        else{
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }

        vertices.push_back(vertex);
    }
}