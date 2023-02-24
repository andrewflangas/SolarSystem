#ifndef PLANET_H
#define PLANET_H
#include <cstring>

class Planet{
public:
    Planet(std::string modelPath, std::string texturePath, float radius, float orbitRadius, float orbitSpeed, float rotationSpeed);
    void update(float deltaTime);
    void draw(Shader &shader, glm::mat4& projection, glm::mat4& view);
    glm::mat4 getModelMatrix();
    glm::vec3 getPosition();

private:
    Model m_Model;
    glm::vec3 m_Position;
    float m_Radius;
    float m_OrbitRadius;
    float m_OrbitSpeed;
    float m_RotationSpeed;
    float m_OrbitAngle;
    float m_RotationAngle;
    void updatePosition();
};
#endif