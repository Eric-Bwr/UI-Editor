#include "Application.h"

void Application::keyCallback(int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_LEFT_ALT && action == GLFW_PRESS)
        alive = false;
    img->setPosition(img->positionX + 1.0f, img->positionY);
    ui.keyInput(key, action, mods);
}

void Application::charCallback(unsigned int key) {
    ui.charInput(key);
}

void Application::mousePositionCallback(double x, double y) {
    ui.mousePositionInput(x, y);
}

void Application::mouseButtonCallback(int button, int action, int mods) {
    ui.mouseButtonInput(button, action);
}

void Application::scrollCallback(double x, double y) {}

void Application::resizeCallback(int width, int height) {
    ui.setSize(width, height);
}

void Application::closeCallback() {}