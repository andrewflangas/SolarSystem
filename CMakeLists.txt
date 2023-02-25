# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(solar_system_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenGL and GLFW libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(include)

# Source files
set(SOURCES
        src/main.cpp
        src/camera.cpp
        src/planet.cpp
        src/ui.cpp
)

# Header files
set(HEADERS
        include/camera.h
        include/model.h
        include/planet.h
        include/shader.h
        include/ui.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link OpenGL and GLFW libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)