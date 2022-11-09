#pragma once

#include <UI/UIManager.h>
#include <Window/WindowManager.h>

class ProgramScreen : public Window {
public:
    void init(const char* name, int width, int height);
    void render();
    void end();
private:
    void computeFile();
    UIManager ui;
};