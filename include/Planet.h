#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <nlohmann/json.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "TextureLoader.h"

class Planet {
public:
    Planet(const nlohmann::json& planetData);
    ~Planet();
    void Update(float deltaTime);
    void Render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);

private:
    std::string name;
    float distanceFromSun;
    float orbitSpeed;
    float rotationSpeed;
    float size;
    std::string textureFile;
    glm::vec3 position;
    glm::mat4 rotation;
    GLuint texture;
    float orbitAngle = 0.0f;
    GLuint vao;
    GLuint vbo;
    Shader shader;
};

#endif
