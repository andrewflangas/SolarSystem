#include "Planet.h"
#include <stdexcept>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Planet::Planet(const nlohmann::json &planetData) {
    // Initialize planet attributes from the JSON object
    name = planetData["name"];
    distanceFromSun = planetData["distance_from_sun"];
    orbitSpeed = planetData["orbit_speed"];
    rotationSpeed = planetData["rotation_speed"];
    size = planetData["size"];
    textureFile = planetData["texture_file"];

    // Load planet texture using Assimp library
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("texture/" + textureFile, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::runtime_error("Failed to load planet texture");
    }

    aiMaterial *material = scene->mMaterials[0];
    if(!material){
        throw std::runtime_error("Failed to load planet material");
    }

    aiString texturePath;
    if(material->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath) == AI_SUCCESS){
        texture = TextureLoader::LoadTexture(texturePath.C_Str());
    }
    else{
        throw std::runtime_error("Failed to load planet texture");
    }

    // Set initial position and rotation
    position = glm::vec3(distanceFromSun, 0.0f, 0.0f);
    rotation = glm::mat4(1.0f);

    // Create vertex buffer object
    float vertices[] = {
        1.0f,  1.0f, 0.0f,  // top right
        1.0f, -1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 0.0f,  // bottom left
        -1.0f,  1.0f, 0.0f   // top left
    };

    unsigned int indices[] = {
        0, 1, 3,  // first triangle
        1, 2, 3   // second triangle
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create shader program
    shader = Shader("planet.vs", "planet.fs");
}

Planet::~Planet() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void Planet::Update(float deltaTime) {
    // Update position based on orbit speed
    float angle = glm::radians(orbitAngle);
    position = glm::vec3(distanceFromSun * glm::cos(angle), 0.0f, distanceFromSun * glm::sin(angle));
    orbitAngle += orbitSpeed * deltaTime;

    // Update rotation based on rotation speed
    float rotationAngle = rotationSpeed * deltaTime;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
    rotation = rotationMatrix * rotation;
}

void Planet::Render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
    // Use shader program
    shader.use();

    // Set model matrix
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix *= rotation;
    modelMatrix = glm::scale(modelMatrix, glm::vec3(size, size, size));
    shader.setMat4("modelMatrix", modelMatrix);

    // Set view matrix
    shader.setMat4("viewMatrix", viewMatrix);

    // Set projection matrix
    shader.setMat4("projectionMatrix", projectionMatrix);

    // Bind planet texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Render planet
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}