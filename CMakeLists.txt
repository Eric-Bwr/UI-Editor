cmake_minimum_required(VERSION 3.16)

add_subdirectory(Dependencies)


project(UI-Editor)

initDeps()

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h")
include_directories(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

afterExec()
