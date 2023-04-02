# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(solar_system_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenGL and GLFW libraries
find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
include_directories(
        ${OPENGL_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

include_directories(include)

# Source files
set(SOURCES
        src/main.cpp
        )

# Header files
set(HEADERS
        include/Planet.h src/Planet.cpp include/TextureLoader.h src/TextureLoader.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link the libraries
target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        ${GLFW_LIBRARIES}
        ${GLM_LIBRARIES}
        )