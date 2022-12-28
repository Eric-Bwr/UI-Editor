#include <iostream>
#include "MainScreen.h"
#include "UI/UIStructure/DataManager.h"

void MainScreen::init() {
    width = 300;
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
    fieldWidth.init("Width", &font, 2, offsetX, height - offsetY - sizeY * 2, width - offsetX * 2, sizeY, 2);
    fieldHeight.init("Height", &font, 2, offsetX, height - offsetY, width - offsetX * 2, sizeY, 2);
    fieldWidth.setBackgroundColor({0.4, 0.4, 0.4, 0.4}, {0.5, 0.5, 0.5, 0.5}, {0.7, 0.7, 0.7, 0.7});
    fieldHeight.setBackgroundColor(fieldWidth.bgColor.standard, fieldWidth.bgColor.hover, fieldWidth.bgColor.pressed);
    fieldWidth.setContentCallback(CALLBACK(MainScreen::fieldWidthCallback));
    fieldHeight.setContentCallback(CALLBACK(MainScreen::fieldHeightCallback));
    fieldWidth.setOnlyNumbers(true);
    fieldHeight.setOnlyNumbers(true);
    //this->ui.add(fieldWidth);
    //this->ui.add(fieldHeight);


    list.init(0, 0, 200, 550, 20, &font);
    list.addEntry("test1g");
    list.addEntry("test2");
    list.addEntry("test3");
    list.addEntry("test4");
    list.entries.at(0)->setBackgroundColor(COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    list.entries.at(1)->setBackgroundColor(COLOR_BLUE, COLOR_BLUE, COLOR_BLUE);
    list.entries.at(2)->setBackgroundColor(COLOR_GREEN, COLOR_GREEN, COLOR_GREEN);
    list.entries.at(3)->setBackgroundColor(COLOR_CYAN, COLOR_CYAN, COLOR_CYAN);
    this->ui.add(list);

    for(int i = 0; i < 20; i++) {
        this->text[i].init((std::to_string(i) + " Hallo").data(), DataManager::defaultFont, i, 210, i * 20, 200, 30, CENTERED_VERTICAL_LEFT);
        this->ui.add(text[i]);
    }
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
    if(width < 400 && height < 400)
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
