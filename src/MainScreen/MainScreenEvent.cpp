#include "MainScreen.h"

void MainScreen::keyCallback(int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_LEFT_ALT && action == GLFW_PRESS)
        alive = false;
    ui.keyInput(key, action, mods);
}

void MainScreen::charCallback(unsigned int key) {
    ui.charInput(key);
}

void MainScreen::mousePositionCallback(double x, double y) {
    ui.mousePositionInput(x, y);
}

void MainScreen::mouseButtonCallback(int button, int action, int mods) {
    ui.mouseButtonInput(button, action);
}

void MainScreen::scrollCallback(double x, double y) {}

void MainScreen::resizeCallback(int width, int height) {
    ui.setSize(width, height);
}

void MainScreen::closeCallback() {}
