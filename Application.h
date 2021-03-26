#ifndef PANGEA_APPLICATION_H
#define PANGEA_APPLICATION_H
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <fstream>
#include "Window.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Shader.h"
#include "ElementBuffers.h"

#include "3rdparty/glfw/deps/linmath.h"

 static const GLchar* vertex_source = R"glsl(
    #version 130
    layout (location = 0) in vec2 position;
    layout (location = 1) in vec3 color;
    layout (location = 2) in vec2 texcoord;
    layout (location = 3) in float tex_index;

    out vec3 Color;
    out vec2 Texcoord;
    out float TexIndex

    void main()
    {
        Color = color;
        Texcoord = texcoord;
        TexIndex = tex_index;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";

static const GLchar* fragment_source = R"glsl(
    #version 130
    in vec3 Color;
    in vec2 Texcoord;
    in float TexIndex;

    layout(location = 0) out vec4 outColor;

    uniform sampler2D Textures[4];
    void main()
    {
        int index = int(TexIndex);
        outColor = texture(Textures[index], Texcoord);
    }
)glsl";

static GLfloat vertices[] = {
        //  Position   Colors             Texcoords
        -1.0f,  1.0f, 0.18f, 0.6f, 0.96f, 0.0f, 0.0f, 0.0f, // Top-left
        0.0f,  1.0f, 0.18f, 0.6f, 0.96f, 1.0f, 0.0f, 0.0f, // Top-right
        0.0f, 0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 1.0f, 0.0f, // Bottom-right
        -1.0f, 0.0f, 0.18f, 0.6f, 0.96f, 0.0f, 1.0f,0.0f, // Bottom-left

        //  Position     Color         Texcoords
        0.0f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left
        1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-right
        1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
        0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  1.0f, // Bottom-left

        //  Position      Colors        Texcoords
        0.0f,  0.0f, 0.0f, 1.0f, 0.93f, 0.0f, 0.0f, 2.0f, // Top-left
        1.0f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f, // Top-right
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, // Bottom-right
        0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  2.0f, // Bottom-left

        //  Position        Colors        Texcoords
        -1.0f,  0.0f, 0.18f, 0.6f, 0.96f, 0.0f, 0.0f, 3.0f, // Top-left
        0.0f,  0.0f, 0.18f, 0.6f, 0.96f, 1.0f, 0.0f, 3.0f, // Top-right
        0.0f, -1.0f, 0.18f, 0.6f, 0.96f, 1.0f, 1.0f, 3.0f, // Bottom-right
        -1.0f, -1.0f, 0.18f, 0.6f, 0.96f, 0.0f, 1.0f, 3.0f, // Bottom-left
};

static GLuint elements[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12
};

class Application {
public:
    explicit Application();
    ~Application();

    void run();
private:
    void _render();
    unsigned int _x{0}, _y{0}, _z{1};
    int _img_width, _img_height;
    int height, width;

    std::vector<std::unique_ptr<VertexArray>> vaos;
    std::vector<std::unique_ptr<VertexBuffer>> vbos;

    std::vector<std::unique_ptr<Texture>> texs;

    GLFWwindow* window;
};

#endif //PANGEA_APPLICATION_H
