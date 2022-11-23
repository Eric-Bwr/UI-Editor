#pragma once

#include <UI/UIManager.h>
#include <Window/WindowManager.h>

class ProgramScreen : public Window {
public:
    void init(const char* name, int width, int height);
    void render();
    void end();

    void keyCallback(int key, int scancode, int action, int mods);
    void charCallback(unsigned int key);
    void mousePositionCallback(double x, double y);
    void mouseButtonCallback(int button, int action, int mods);
    void scrollCallback(double x, double y);
    void resizeCallback(int width, int height);
    void closeCallback();
private:
    void computeFile();
    UIManager ui;
};