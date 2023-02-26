#include "planet.h"

Planet::Planet(std::string modelPath, std::string texturePath, float radius, float orbitRadius, float orbitSpeed,
               float rotationSpeed) {
    updatePosition();
}

void Planet::update(float deltaTime) {
    m_OrbitAngle += m_OrbitSpeed * deltaTime;
    m_RotationAngle += m_RotationSpeed * deltaTime;

    updatePosition();
}

void Planet::draw(Shader &shader, glm::mat4 &projection, glm::mat4 &view) {
    shader.use();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    glm::mat4 model = getModelMatrix();
    shader.setMat4("model", model);

    m_Model.draw(shader);
}

glm::mat4 Planet::getModelMatrix() {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, m_Position);
    model = glm::rotate(model, glm::radians(m_RotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(m_Radius));
    return model;
}

glm::vec3 Planet::getPosition() {
    return m_Position;
}

void Planet::updatePosition() {
    float x = m_OrbitRadius * cos(glm::radians(m_OrbitAngle));
    float z = m_OrbitRadius * sin(glm::radians(m_OrbitAngle));
    m_Position = glm::vec3(x, 0.0f, z);
}