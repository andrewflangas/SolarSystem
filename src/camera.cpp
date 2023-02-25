#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up)
    : m_Position(position), m_Front(glm::normalize(front)), m_Up(glm::normalize(up)), m_WorldUp(glm::normalize(up)),
    m_Yaw(-90.0f), m_Pitch(0.0f), m_Speed(2.5f), m_Sensitivity(0.1f), m_Zoom(45.0f)
{
    updateCameraVectors();
}

void Camera::processKeyboard(int key, float deltaTime)
{
    float velocity = m_Speed * deltaTime;
    if(key == GLFW_KEY_W)
        m_Position += m_Front * velocity;
    if(key == GLFW_KEY_S)
        m_Position -= m_Front * velocity;
    if(key == GLFW_KEY_A)
        m_Position -= m_Right * velocity;
    if(key == GLFW_KEY_D)
        m_Position += m_Right * velocity;
}

void Camera::processMouseMovement(float xoffset, float yoffset)
{

}