#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <SOIL/SOIL.h>

#include "3rdparty/glfw/deps/linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "Window.h"



// Shader sources

/*static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}*/

int main(void)
{
    /*glfwSetErrorCallback(error_callback);*/

    /*GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

    char buffer[512];
    if (status != GL_TRUE) {
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        std::fstream fs;
        fs.open("log.txt", std::ios::out | std::ios::trunc);
        fs << buffer;
        fs.close();
    }*/

    std::string title{"pangea"};
    std::unique_ptr<Window> window{ new Window{ 1024, 512, title }};
    while (!window->should_close())
    {
        window->update_screen();
    }

    exit(EXIT_SUCCESS);

    return 0;
}
