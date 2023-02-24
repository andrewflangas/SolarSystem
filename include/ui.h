#ifndef UI_H
#define UI_H

class UI{
public:
    UI(GLFwindow* window);
    bool isKeyPressed(int key);
    bool isMouseButtonPressed(int button);
    bool isMouseMoved();
    void getMousePosition(double& xpos, double& ypos);
    void processInput(float deltaTime);
    void swapBuffers();
    void pollEvents();

private:
    GLFWindow* m_Window;
    double m_LastX;
    double m_LastY;
    bool m_FirstMouse;
};
#endif