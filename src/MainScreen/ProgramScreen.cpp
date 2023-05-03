#include "MainScreen.h"
#include <Math/AABB.h>

const float listWidth = 170;
const float listWidthHalf = listWidth / 2;

void MainScreen::setup(){
    list.init(0, 0, listWidth, AUTO_HEIGHT, 30, &font);
    list.setCallback(CB_3(MainScreen::listCallback));
    list.addEntry("Image", 2.0f);
    list.addEntry("Button", 2.0f);
    list.addEntry("Circular Bar", 2.0f);
    list.addEntry("List", 2.0f);
    list.addEntry("Slider", 2.0f);
    list.addEntry("Switch", 2.0f);
    list.addEntry("Text", 2.0f);
    list.addEntry("Text Field", 2.0f);
    list.addEntry("Text Area", 2.0f);
    list.setRadii(5, 1, 1, 1, 1);
}

void MainScreen::showList() {
    float x = this->ui.mouseX;
    float y = this->ui.mouseY;

    if(this->ui.contains(list) && x > list.positionX && y > list.positionY && x < list.positionX + list.width && y < list.positionY + list.height){
        this->ui.remove(list);
        return;
    }

    auto listHeightHalf = list.height / 2;

    summonX = x;
    summonY = y;

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
    if(pressed && hovered)
        addElement(entryIndex);
}

template<typename T>
T MainScreen::add(T component) {
    this->elements.push_back(component);
    this->ui.add(component);
    return component;
}

void MainScreen::addElement(int id) {
    if(id != 2 && id < 6 && id > 8){
        summonX -= DEFAULT_WIDTH / 2.0f;
        summonY -= DEFAULT_HEIGHT / 2.0f;
    }
    if(id == 0)
        add(new UIImage())->init(summonX, summonY);
    else if(id == 1)
        add(new UIButton())->init(summonX, summonY);
    else if(id == 2)
        add(new UICircularBar())->init(summonX - 150, summonY - 150, 300, 300);
    else if(id == 3)
        add(new UIList())->init(summonX, summonY);
    else if(id == 4)
        add(new UISlider())->init(summonX, summonY);
    else if(id == 5)
        add(new UISwitch())->init(summonX, summonY);
    else if(id == 6)
        add(new UIText())->init("Text", &font, 20, summonX - 50, summonY - 15, 100, 30, UITextMode::CENTERED_VERTICAL_LEFT);
    else if(id == 7)
        add(new UITextField())->init("Text Field", &font, 20, summonX - 100, summonY - 15, 200, 30);
    else if(id == 8)
        add(new UITextArea())->init(&font, 20, summonX - 150, summonY - 150, 300, 300);
}

void MainScreen::isHoveringOnElement(){
    float x = this->ui.mouseX;
    float y = this->ui.mouseY;
    for(const auto& element : elements){
        if(AABB::inside(element->positionX, element->positionY, element->width, element->height, x, y)){
            currentElement = element;
            break;
        }
    }
}

void MainScreen::moveElement() {
    //TODO: CONFINE TO WINDOW
    //TODO: SNAP TO OTHER ELEMENTS
    if(currentElement != nullptr){
        float x = this->ui.mouseX;
        float y = this->ui.mouseY;
        currentElement->setPosition(x - currentElement->width / 2.0f, y - currentElement->height / 2.0f);
    }
}
