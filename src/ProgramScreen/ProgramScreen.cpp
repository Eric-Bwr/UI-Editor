#include "ProgramScreen.h"

void ProgramScreen::init(const char *name, int width, int height) {
    this->hint(GLFW_RESIZABLE, GLFW_FALSE);
    this->initWindow(name, width, height);
    this->center(WindowManager::getVideoMode()->width);
    this->setMouse(width / 2.0, height / 2.0);

    this->ui.init(width, height);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(0, 0, width, height);

    WindowManager::addWindow(this);
}

void ProgramScreen::render() {
    this->context();
    glClear(GL_COLOR_BUFFER_BIT);
    this->ui.render();
    this->swapBuffers();
}

void ProgramScreen::end() {

}

void ProgramScreen::computeFile() {
    
}
