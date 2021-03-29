#ifndef PANGEA_APPLICATION_H
#define PANGEA_APPLICATION_H
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <fstream>
#include "VertexArray.h"
#include "Texture.h"
#include "Shader.h"
#include "ElementBuffers.h"

#include "3rdparty/glfw/deps/linmath.h"

static GLfloat vertices1[] = {
        //  Position  Texcoords
        -1.0f, 1.0f, 0.0f, 0.0f, // Top-left
        0.0f, 1.0f, 1.0f, 0.0f, // Top-right
        0.0f, 0.0f, 1.0f, 1.0f, // Bottom-right
        -1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left

};

static GLfloat vertices2[] = {
        //  Position  Texcoords
        0.0f, 1.0f, 0.0f, 0.0f, // Top-left
        1.0f, 1.0f, 1.0f, 0.0f, // Top-right
        1.0f, 0.0f, 1.0f, 1.0f, // Bottom-right
        0.0f, 0.0f, 0.0f, 1.0f, // Bottom-left
};

static GLfloat vertices3[] = {
        //  Position  Texcoords
        0.0f,  0.0f, 0.0f, 0.0f, // Top-left
        1.0f,  0.0f, 1.0f, 0.0f, // Top-right
        1.0f, -1.0f, 1.0f, 1.0f, // Bottom-right
        0.0f, -1.0f, 0.0f, 1.0f, // Bottom-left
};

static GLfloat vertices4[] = {
        //  Position  Texcoords
        -1.0f,  0.0f, 0.0f, 0.0f, // Top-left
        0.0f,  0.0f, 1.0f, 0.0f, // Top-right
        0.0f, -1.0f, 1.0f, 1.0f, // Bottom-right
        -1.0f, -1.0f, 0.0f, 1.0f, // Bottom-left
};

static GLuint elements1[] = {
        0, 1, 2,
        2, 3, 0
};

class Application {
public:
    explicit Application(GLFWwindow*, const char*, const char*);
    ~Application();

    void render();

    static void zoom();
    static void unzoom();
    static void move_north();
    static void move_south();
    static void move_west();
    static void move_east();
private:
    void _init();
    static void _load_all_textures();
    static unsigned char* _load_image();
    static void _download_image(const std::string&) noexcept;


    static unsigned int _x, _y, _z;
    static int height, width;

    std::vector<std::unique_ptr<VertexArray>> _vaos;
    std::vector<std::unique_ptr<VertexBuffer>> _vbos;
    static std::vector<std::unique_ptr<Texture>> _texs;

    std::shared_ptr<ElementBuffers> _ebo;
    Shader _shader;
    ElementBuffers ebo{elements1, sizeof(elements1)};

    GLFWwindow* _window;
};

#endif //PANGEA_APPLICATION_H
