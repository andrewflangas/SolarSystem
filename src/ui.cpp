#include "ui.h"

UI::UI(GLFWwindow* window): m_Window(window), m_LastX(0.0), m_LastY(0.0), m_FirstMouse(true){}

bool UI::isKeyPressed(int key) {
    return glfwGetKey(m_Window, key) == GLFW_PRESS;
}

bool UI::isMouseButtonPressed(int button) {
    return glfwGetMouseButton(m_Window, button) == GLFW_PRESS;
}

bool UI::isMouseMoved() {
    double xpos, ypos;
    glfwGetCursorPos(m_Window, &xpos, &ypos);
    if(m_FirstMouse){
        m_LastX = xpos;
        m_LastY = ypos;
        m_FirstMouse = false;
        return false;
    }

    return (xpos != m_LastX || ypos != m_LastY);
}

void UI::getMousePosition(double &xpos, double &ypos) {
    glfwGetCursorPos(m_Window, &xpos, &ypos);
}

void UI::processInput(float deltaTime) {
    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(m_Window, true);
    }
}

void UI::swapBuffers() {
    glfwSwapBuffers(m_Window);
}

void UI::pollEvents() {
    glfwPollEvents();
}