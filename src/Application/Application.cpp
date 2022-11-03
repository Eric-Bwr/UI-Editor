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
    logger.setLogFile("Logs");
    logInfo("Pre init...");
    width = 1600 - 100;
    height = 800 - 100;
    WindowManager::init(4, 3);

    this->initWindow("UI-Editor", width, height);
    this->setIcon("../Assets/Textures/Icon.png");
    this->center(WindowManager::getVideoMode()->width * 2);

    this->ui.init(width, height);
    this->img = new UIImage(20, 20, 40, 40);
    this->button = new UIButton(20, 80, 40, 40);
    this->circularBar = new UICircularBar(80, 20, 200, 200);
    this->scrollbar = new UIScrollbar(circularBar, 80, 20, 200, 100);
    this->slider = new UISlider(80, 200, 200, 100);
    this->splitPane = new UISplitPane(80, 200, 200, 100);
    this->ui.add(this->img);
    this->ui.add(this->button);
    this->ui.add(this->scrollbar);
    this->ui.add(this->circularBar);
    this->ui.add(this->slider);
    this->ui.add(this->splitPane);
    this->button->setText("TW");
    this->button->setFontSize(20);
    this->circularBar->setColor({0, 0, 0, 0});
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(0, 0, width, height);


    test.initWindow("UI-Editor2", width, height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    test.ui.init(width, height);
    test.img = new UIImage(20, 80, 40, 40);
    test.ui.add(test.img);

    WindowManager::addWindow(this);
    WindowManager::addWindow(&test);

    this->setMouse(width / 2.0, height / 2.0);
    glViewport(0, 0, width, height);
    logInfo("Initialized OpenGL");
}

void Application::init() {
    logInfo("Init...");
    lastTime = glfwGetTime();
}

void Application::run() {
    logInfo("Run...");
    while(alive){
        double lastFrameTime = glfwGetTime();
        WindowManager::pollEvents();

        this->context();
        glClear(GL_COLOR_BUFFER_BIT);
        this->ui.render();

        test.context();
        glClear(GL_COLOR_BUFFER_BIT);
        test.ui.render();

        this->swapBuffers();
        test.swapBuffers();

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
}