#pragma once

#include <UI/UIManager.h>
#include <Window/WindowManager.h>

class MainScreen : public Window {
public:
    void init();
    void render();
    void end();
private:
    void switchBetween();
    void setup();
    void showList();
    void createWindow(bool shift);
    UIManager ui;
    UIImage backgroundImage;
    Texture backgroundTexture;
    Font font;
    UIList list;
    UITextField fieldWidth, fieldHeight;
    std::vector<UIComponent*> elements;
    float summonX = 0.0f, summonY = 0.0f;
    template<typename T>
    T add(T component);
    int width, height;
    bool editing = false;
    bool shiftPressed = false;
    UIComponent* currentElement = nullptr;
    void listCallback(bool pressed, bool hovered, int entryIndex);
    void addElement(int id);
    void moveElement();
    void isHoveringOnElement();

    void fieldWidthCallback(std::string content, std::string passwordContent);
    void fieldHeightCallback(std::string content, std::string passwordContent);

    void keyCallback(int key, int scancode, int action, int mods) override;
    void charCallback(unsigned int key) override;
    void mousePositionCallback(double x, double y) override;
    void mouseButtonCallback(int button, int action, int mods) override;
    void scrollCallback(double x, double y) override;
    void resizeCallback(int width, int height) override;
    void closeCallback() override;
};