#include "MainScreen.h"

void MainScreen::keyCallback(int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS){
        if (key == GLFW_KEY_LEFT_ALT && mods == GLFW_MOD_CONTROL)
            alive = false;
        else if(key == GLFW_KEY_ENTER)
            createWindow(mods == GLFW_MOD_SHIFT);
        else if(key == GLFW_KEY_TAB)
            switchBetween();
    }
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
