#include <stdlib.h>
#include <string>
#include <memory>
#include "Application.h"

static const GLchar* vertex_source = R"glsl(
    #version 130
    in vec2 position;
    in vec3 color;
    in vec2 texcoord;
    out vec3 Color;
    out vec2 Texcoord;
    void main()
    {
        Color = color;
        Texcoord = texcoord;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";

static const GLchar* fragment_source = R"glsl(
    #version 130
    in vec3 Color;
    in vec2 Texcoord;
    out vec4 outColor;
    uniform sampler2D tex;
    void main()
    {
        outColor = texture(tex, Texcoord);
    }
)glsl";

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    else if (key == GLFW_KEY_Z && action == GLFW_PRESS)
        Application::zoom();
    else if (key == GLFW_KEY_W && action == GLFW_PRESS)
        Application::move_north();
    else if (key == GLFW_KEY_X && action == GLFW_PRESS)
        Application::unzoom();
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        Application::move_south();
    else if (key == GLFW_KEY_D && action == GLFW_PRESS)
        Application::move_east();
    else if (key == GLFW_KEY_A && action == GLFW_PRESS)
        Application::move_west();
}

int main()
{
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(768, 768, "Pangea", nullptr, nullptr);


    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    Application application{window, vertex_source, fragment_source};
    application.render();

    exit(EXIT_SUCCESS);

    return 0;
}
