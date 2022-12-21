#pragma once

#include <UI/UIManager.h>
#include <Window/WindowManager.h>

class MainScreen : public Window {
public:
    void init();
    void render();
    void end();
private:
    UIManager ui;
    UIImage backgroundImage;
    Texture backgroundTexture;
    int width, height;
    void keyCallback(int key, int scancode, int action, int mods) override;
    void charCallback(unsigned int key) override;
    void mousePositionCallback(double x, double y) override;
    void mouseButtonCallback(int button, int action, int mods) override;
    void scrollCallback(double x, double y) override;
    void resizeCallback(int width, int height) override;
    void closeCallback() override;
};