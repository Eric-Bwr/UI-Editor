#include <UI/UIManager.h>
#include <OpenGL/OpenGL.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>

static UIManager uiManager;

static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    uiManager.keyInput(key, scancode, action);
}

static void charCallback(GLFWwindow *window, unsigned int key) {
    uiManager.charInput(key);
}

static void mousePositionCallback(GLFWwindow *window, double x, double y) {
    uiManager.mousePositionInput(x, y);
}

static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    uiManager.mouseButtonInput(button, action);
}

static void scrollCallback(GLFWwindow *window, double x, double y) {
}

static void resizeCallback(GLFWwindow *window, int width, int height) {
    uiManager.setSize(width, height);
}

int main(){
    if(!glfwInit())
        return -1;
    GLFWwindow* window = glfwCreateWindow(800, 400, "UI-Editor", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCharCallback(window, charCallback);
    glfwSetCursorPosCallback(window, mousePositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetFramebufferSizeCallback(window, resizeCallback);

    if(!gladLoadGL(glfwGetProcAddress))
        return 2;

    uiManager.init(800, 400);
    glViewport(0, 0, 800, 400);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    while(!glfwWindowShouldClose(window)) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        glClear(GL_COLOR_BUFFER_BIT);
        uiManager.render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
}