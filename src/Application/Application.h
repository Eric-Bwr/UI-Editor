#pragma once

#include <Logger/Logger.h>
#include <csignal>
#include <ctime>
#include <OpenGL/Texture.h>
#include <OpenGL/OpenGL.h>
#include <Window/WindowManager.h>
#include <UI/UIManager.h>

class Application : public Window {
public:
    void preInit();
    void init();
    void run();
    void end();

    int width, height;
    int frames = 0;
    double lastTime = 0, currentTime = 0;
    double frameDeltaTime = 0;
    UIManager ui;
    UIImage* img;
    UIButton* button;
    UICircularBar* circularBar;
    UIScrollbar* scrollbar;
    UISlider* slider;
    UISplitPane* splitPane;
    UISwitch* switchUI;
    UIText* text;
    UITextArea* textArea;
    UITextField* textField;
    Font* font;
private:
    void keyCallback(int key, int scancode, int action, int mods) override;
    void charCallback(unsigned int key) override;
    void mousePositionCallback(double x, double y) override;
    void mouseButtonCallback(int button, int action, int mods) override;
    void scrollCallback(double x, double y) override;
    void resizeCallback(int width, int height) override;
    void closeCallback() override;
};

extern Application application;