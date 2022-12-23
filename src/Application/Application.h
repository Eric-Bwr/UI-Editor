#pragma once

#include <Logger/Logger.h>
#include <csignal>
#include <ctime>
#include <OpenGL/Texture.h>
#include <OpenGL/OpenGL.h>
#include <Window/WindowManager.h>

#include "../MainScreen/MainScreen.h"

class Application {
public:
    void preInit();
    void init();
    void run();
    void end();

    int frames = 0;
    double lastTime = 0, currentTime = 0;
    double frameDeltaTime = 0;
private:
    MainScreen* mainScreen;
};

extern Application application;