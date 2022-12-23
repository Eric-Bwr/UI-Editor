#include "Application.h"
#include <iostream>

Application application;

void terminateHandler() {
    logError("Unhandled exception");
    std::abort();
}

extern "C" void handleAborts(int signalNumber) {
    logError("Signal received, shutting down...");
    std::flush(std::cerr);
    std::flush(std::cout);
    exit(3);
}

int main(){
    std::set_terminate(terminateHandler);
    signal(SIGSEGV, &handleAborts);
    signal(SIGTERM, &handleAborts);
    signal(SIGABRT, &handleAborts);
    application = Application();
    application.preInit();
    application.init();
    application.run();
    application.end();
}

void Application::preInit() {
    logPath("Logs");
    logInfo("Pre init...");
    WindowManager::init(4, 3);

    mainScreen = new MainScreen();

    logInfo("Initialized OpenGL");
}

void Application::init() {
    logInfo("Init...");
    lastTime = glfwGetTime();

    mainScreen->init();
}

void Application::run() {
    logInfo("Run...");
    while(mainScreen->alive){
        double lastFrameTime = glfwGetTime();
        WindowManager::pollEvents();

        mainScreen->render();

        currentTime = glfwGetTime();
        frameDeltaTime = currentTime - lastFrameTime;
        frames++;
        if(currentTime - lastTime >= 1.0){
            frames = 0;
            lastTime++;
        }
    }
}

void Application::end() {
    logInfo("Shutting down...");
    delete mainScreen;
    logInfo("Shut down");
}