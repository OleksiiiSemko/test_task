#include <stdlib.h>
#include <string>
#include <memory>
#include "Window.h"
#include "Application.h"

/*
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    else if (key == GLFW_KEY_Z && action == GLFW_PRESS)
        zoom();
    else if (key == GLFW_KEY_W && action == GLFW_PRESS)
        move_north();
    else if (key == GLFW_KEY_X && action == GLFW_PRESS)
        unzoom();
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        move_south();
    else if (key == GLFW_KEY_D && action == GLFW_PRESS)
        move_east();
    else if (key == GLFW_KEY_A && action == GLFW_PRESS)
        move_west();
}
*/
/*glfwSetKeyCallback(_window.get_window_ptr(), key_callback);*/

// Shader sources

/*static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}*/

int main()
{

    Application application{};

    application.run();

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


    exit(EXIT_SUCCESS);

    return 0;
}
