#include <iostream>
#include "MainScreen.h"

const float listWidth = 100;
const float listHeight = 30 * 5 + 2;
const float listWidthHalf = listWidth / 2;
const float listHeightHalf = listHeight / 2;

void MainScreen::setup(){
   // list.init(0, 0, listWidth, AUTO_HEIGHT, 30, &font);
    list.init(0, 0, listWidth, listHeight, 30, &font);
    list.setCallback(CB_3(MainScreen::listCallback));
    list.setBackgroundColor(COLOR_RED);
    list.addEntry("Test");
    list.addEntry("Test", 2);
    list.addEntry("Test");
    list.addEntry("Test");
    list.addEntry("Test");
    list.setRadii(5, 1, 1, 1, 1);
}

void MainScreen::showList() {
    float x = this->ui.mouseX;
    float y = this->ui.mouseY;

    if(this->ui.contains(list) && x > list.positionX && y > list.positionY && x < list.positionX + list.width && y < list.positionY + list.height){
        this->ui.remove(list);
        return;
    }

    if(x - listWidthHalf < 0)
        x = listWidthHalf;
    if(y - listHeightHalf < 0)
        y = listHeightHalf;

    if(x + listWidthHalf > width)
        x = width - listWidthHalf;
    if(y + listHeightHalf > height)
        y = height - listHeightHalf;

    x -= listWidthHalf;
    y -= listHeightHalf;

    this->list.setPosition(x, y);
    this->ui.add(list);
}

void MainScreen::listCallback(bool pressed, bool hovered, int entryIndex) {
    std::cout << entryIndex << ": " << pressed << " " << hovered << std::endl;
}