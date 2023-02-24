#ifndef CAMERA_H
#define CAMERA_H

class Camera{
public:
    Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);
    void processKeyboard(int key, float deltaTime);
    void processMouseMovement(float xoffset, float yoffest);
    glm::mat4 getViewMatrix();

private:
    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;
    float m_Yaw;
    float m_Pitch;
    float m_Speed;
    float m_Sensitivity;
    float m_Zoom;
    void updateCameraVectors();
};
#endif