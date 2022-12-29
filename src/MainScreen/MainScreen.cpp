#include <iostream>
#include "MainScreen.h"
#include "UI/UIStructure/DataManager.h"
#include "UI/UIComponents/Text/Structure/FontType.h"

void MainScreen::init() {
    width = 500;
    height = 200 * 3;
    this->hint(GLFW_RESIZABLE, GLFW_FALSE);
    this->initWindow("UI-Editor", width, height);
    this->setIcon("../Assets/Textures/Icon.png");
    this->center(WindowManager::getVideoMode()->width * 2);
    this->setMouse(width / 2.0, height / 2.0);

    this->ui.init(width, height, true);

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
    fieldWidth.init("Width", &font, 40, offsetX, height - offsetY - sizeY * 2, width - offsetX * 2, sizeY, 2);
    fieldHeight.init("Height", &font, 40, offsetX, height - offsetY, width - offsetX * 2, sizeY, 2);
    fieldWidth.setBackgroundColor({0.4, 0.4, 0.4, 0.4}, {0.5, 0.5, 0.5, 0.5}, {0.7, 0.7, 0.7, 0.7});
    fieldHeight.setBackgroundColor(fieldWidth.bgColor.standard, fieldWidth.bgColor.hover, fieldWidth.bgColor.pressed);
    fieldWidth.setContentCallback(UICALLBACK(MainScreen::fieldWidthCallback));
    fieldHeight.setContentCallback(UICALLBACK(MainScreen::fieldHeightCallback));
    fieldWidth.setOnlyNumbers(true);
    fieldHeight.setOnlyNumbers(true);
    fieldWidth.setMaxCharacter(4);
    fieldHeight.setMaxCharacter(4);
    this->ui.add(fieldWidth);
    this->ui.add(fieldHeight);

    list.init(0, 0, 200, 550, 20, &font);
    list.addEntry("test1g");
    list.addEntry("test2g");
    list.addEntry("test3");
    list.addEntry("test4");
    this->ui.add(list);
}

void MainScreen::render() {
    this->context();
    glClear(GL_COLOR_BUFFER_BIT);
    this->ui.render();
    this->swapBuffers();
}

void MainScreen::fieldWidthCallback(std::string content, std::string passwordContent) {
    width = atoi(content.data());
}

void MainScreen::fieldHeightCallback(std::string content, std::string passwordContent) {
    height = atoi(content.data());
}

void MainScreen::createWindow(bool shift) {
    if(width < 400 || height < 400 || width > 5000 || height > 5000)
        return;
    glViewport(0, 0, width, height);
    this->setSize(width, height);
    if(shift){
        this->ui.remove(fieldWidth);
        this->ui.remove(fieldHeight);
    }
}

void MainScreen::switchBetween() {
    if(fieldWidth.pressed){
        fieldWidth.pressed = fieldWidth.hovered = false;
        fieldHeight.pressed = fieldHeight.hovered = true;
        fieldHeight.mouseButtonInput(INPUT_PRESSED);
    }else if(fieldHeight.pressed){
        fieldHeight.pressed = fieldHeight.hovered = false;
        fieldWidth.pressed = fieldWidth.hovered = true;
        fieldWidth.mouseButtonInput(INPUT_PRESSED);
    }
}

void MainScreen::end() {

}
