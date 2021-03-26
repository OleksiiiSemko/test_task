#ifndef PANGEA_WINDOW_H
#define PANGEA_WINDOW_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <SOIL/SOIL.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "3rdparty/glfw/deps/linmath.h"

#include <string>
#include <memory>
#include <fstream>
#include <sstream>


class Window {
 public:
    Window(int, int, std::string&);
    void create_texture(); // Create a texture object
    bool should_close();
    void update_screen();
    ~Window();

 private:
    static void key_callback(GLFWwindow*, int, int, int, int);
    static void get_image();
    void create_vao(); // Create vertex array object
    void create_vbo(); // Create a vertex buffer object
    void create_ebo(); // Create an element array
    static void render();

    GLFWwindow* window;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    int width, height;
    static std::string filename;
    static double x, y, z;
};

#endif // PANGEA_WINDOW_H
