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
    void createWindow(bool shift);
    UIManager ui;
    UIImage backgroundImage;
    Texture backgroundTexture;
    Font font;
    UITextField fieldWidth, fieldHeight;
    UIList list;
    UIText text[20];
    std::vector<UIButton> listItems;
    int width, height;

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