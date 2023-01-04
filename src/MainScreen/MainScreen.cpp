#include "MainScreen.h"

void MainScreen::init() {
    width = 400;
    height = 400;
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
    int offsetY = 180;
    int sizeY = 50;
    fieldWidth.init("Width", &font, 40, offsetX, height - offsetY - sizeY * 2, width - offsetX * 2, sizeY, 2);
    fieldHeight.init("Height", &font, 40, offsetX, height - offsetY, width - offsetX * 2, sizeY, 2);
    fieldWidth.setBackgroundColor(UIColor(0x909090), UIColor(0xAAAAAA), UIColor(0xCCCCCC));
    fieldHeight.setBackgroundColor(fieldWidth.bgColor.standard, fieldWidth.bgColor.hover, fieldWidth.bgColor.pressed);
    fieldWidth.setContentCallback(CB_2(MainScreen::fieldWidthCallback));
    fieldHeight.setContentCallback(CB_2(MainScreen::fieldHeightCallback));
    fieldWidth.setOnlyNumbers(true);
    fieldHeight.setOnlyNumbers(true);
    fieldWidth.setMaxCharacter(4);
    fieldHeight.setMaxCharacter(4);
    fieldWidth.setRadii(5);
    fieldHeight.setRadii(5);
    this->ui.add(fieldWidth);
    this->ui.add(fieldHeight);
    setup();
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
    if(editing)
        return;
    if(width < 400 || height < 400 || width > 5000 || height > 5000)
        return;
    glViewport(0, 0, width, height);
    this->setSize(width, height);
    if(shift){
        this->ui.remove(fieldWidth);
        this->ui.remove(fieldHeight);
        editing = true;
    }
}

void MainScreen::switchBetween() {
    if(editing)
        return;
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

void MainScreen::end() {}