#include "camera.h"

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
    xoffset *= m_Sensitivity;
    yoffset *= m_Sensitivity;

    m_Yaw += xoffset;
    m_Pitch += yoffset;

    if (m_Pitch > 89.0f)
        m_Pitch = 89.0f;
    if(m_Pitch < -89.0f)
        m_Pitch = -89.0f;

    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix(){
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::updateCameraVectors() {
    glm::vec3  front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

