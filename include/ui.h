#ifndef UI_H
#define UI_H

#include <iostream>
#include <GLFW/glfw3.h>

class UI{
public:
    UI(GLFWwindow* window);
    bool isKeyPressed(int key);
    bool isMouseButtonPressed(int button);
    bool isMouseMoved();
    void getMousePosition(double& xpos, double& ypos);
    void processInput(float deltaTime);
    void swapBuffers();
    void pollEvents();

private:
    GLFWwindow* m_Window;
    double m_LastX;
    double m_LastY;
    bool m_FirstMouse;
};
#endif