#include "Window.h"
#include <cmath>

GLfloat vertices[] = {
        //  Position      Color             Texcoords
        -1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
        1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Top-right
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
};

GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
};

const GLchar* vertexSource = R"glsl(
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

const GLchar* fragmentSource = R"glsl(
    #version 130
    in vec3 Color;
    in vec2 Texcoord;
    out vec4 outColor;
    uniform sampler2D tex;
    void main()
    {
        outColor = texture(tex, Texcoord) * vec4(Color, 1.0);
    }
)glsl";

Window::Window(int width_, int height_, std::string& title) : width{width_}, height{height_} {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);


    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    create_vao();
    create_vbo();
    create_ebo();
    compile_vertex_shaders(vertexSource);
    compile_fragment_shader(fragmentSource);
    link_shaders();
    specify_layout();
    create_texture();
    render();
}

void Window::render() {
    std::ostringstream temp;
    temp << "../Textures/" << x << y << z << ".png";
    filename = temp.str();
    image = SOIL_load_image(filename.c_str(), &img_width, &img_height, 0, SOIL_LOAD_RGB);
    if (!image) {
        get_image();
        image = SOIL_load_image(filename.c_str(), &img_width, &img_height, 0, SOIL_LOAD_RGB);
    }
    load_texture();
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
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

void Window::get_image() {
    std::fstream fs;
    std::ostringstream url_stream;
    url_stream << "https://api.mapbox.com/styles/v1/mapbox/streets-v11/static/" << x << "," << y << "," << z << "/1024x512?access_token=pk.eyJ1IjoidmFnMW5hIiwiYSI6ImNrbTgwemJodzEzdWcyd254ZWZ1czdrbTQifQ.mcHqUTS2rBhZBN_ZAakxjg";
    fs.open(filename, std::ios::binary | std::ios::out | std::ios::trunc);
    fs << curlpp::options::Url(url_stream.str());
    fs.close();
}

bool Window::should_close() {
    return glfwWindowShouldClose(window);
}

void Window::update_screen() {
    int w_width, w_height;
    glfwGetFramebufferSize(window, &w_width, &w_height);

    // Clear the screen to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a rectangle from the 2 triangles using 6 indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

Window::~Window() {
    glDeleteTextures(1, &tex);

    glDeleteProgram(shader_program);
    glDeleteShader(fragment_shader);
    glDeleteShader(vertex_shader);

    glfwDestroyWindow(window);

    glfwTerminate();
}

double Window::x = 0;
double Window::y = 0;
double Window::z = 0;
int Window::img_width = 0;
int Window::img_height = 0;
unsigned char* Window::image = NULL;
std::string Window::filename{};
