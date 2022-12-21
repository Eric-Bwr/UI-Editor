#include "MainScreen.h"
#include "../Application/Application.h"

void MainScreen::init() {
    width = 600;
    height = 600;
    this->hint(GLFW_RESIZABLE, GLFW_FALSE);
    this->initWindow("UI-Editor", width, height);
    this->setIcon("../Assets/Textures/Icon.png");
    this->center(WindowManager::getVideoMode()->width);
    this->setMouse(width / 2.0, height / 2.0);

    this->ui.init(width, height);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(0, 0, width, height);

    WindowManager::addWindow(this);

    backgroundTexture.init("../Assets/Textures/Icon.png");
    backgroundImage.init(0, 0, width, height);
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setColor({1.0, 1.0, 1.0, 0.2});
    this->ui.add(backgroundImage);
}

void MainScreen::render() {
    this->context();
    glClear(GL_COLOR_BUFFER_BIT);
    this->ui.render();
    this->swapBuffers();
}

void MainScreen::end() {

}