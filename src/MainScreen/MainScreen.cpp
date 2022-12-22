#include <iostream>
#include "MainScreen.h"
#include "UI/UIStructure/DataManager.h"

void MainScreen::init() {
    width = 300;
    height = 200;
    this->hint(GLFW_RESIZABLE, GLFW_FALSE);
    this->initWindow("UI-Editor", width, height);
    this->setIcon("../Assets/Textures/Icon.png");
    this->center(WindowManager::getVideoMode()->width * 2);
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

    font.init("../Assets/arial.ttf");

    int offsetX = 20;
    int offsetY = 80;
    int sizeY = 50;
    fieldWidth.init("Width", &font, 2, offsetX, height - offsetY - sizeY * 2, width - offsetX * 2, sizeY, 2);
    fieldHeight.init("Height", &font, 2, offsetX, height - offsetY, width - offsetX * 2, sizeY, 2);
    fieldWidth.setBackgroundColor({0.4, 0.4, 0.4, 0.4}, {0.5, 0.5, 0.5, 0.5}, {0.7, 0.7, 0.7, 0.7});
    fieldHeight.setBackgroundColor(fieldWidth.bgColor.standard, fieldWidth.bgColor.hover, fieldWidth.bgColor.pressed);
    fieldWidth.setContentCallback(CALLBACK(MainScreen::fieldWidthCallback));
    fieldWidth.setOnlyNumbers(true);
    this->ui.add(fieldWidth);
    this->ui.add(fieldHeight);
}

void MainScreen::render() {
    this->context();
    glClear(GL_COLOR_BUFFER_BIT);
    this->ui.render();
    this->swapBuffers();
}

void MainScreen::fieldWidthCallback(std::string content, std::string passwordContent) {
    std::cout << content << " | " << passwordContent << std::endl;
}

void MainScreen::end() {

}