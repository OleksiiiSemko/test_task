#include "Application.h"
#include <sstream>

Application::Application() {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(512, 512, "Pangea", NULL, NULL);


    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);
    _render();
}

Application::~Application() {
    glfwDestroyWindow(window);
    glfwTerminate();
}



void Application::_render() {
    GLuint _vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(_vertex_shader, 1, &vertex_source, nullptr);
    glCompileShader(_vertex_shader);

    GLuint _fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(_fragment_shader, 1, &fragment_source, nullptr);
    glCompileShader(_fragment_shader);

    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, _vertex_shader);
    glAttachShader(shader_program, _fragment_shader);
    glBindFragDataLocation(shader_program, 0, "outColor");
    glLinkProgram(shader_program);
    glUseProgram(shader_program);

    auto loc = glGetUniformLocation(shader_program, "Textures");
    int samplers[4] = { 0, 1, 2 ,3 };
    glUniform1iv(loc, 4, samplers);

    VertexArray vao;
    VertexBuffer vbo{vertices, sizeof(vertices)};
    glUseProgram(shader_program);
    vao.specify_layout(shader_program, vbo.get_id());

    ElementBuffers elementBuffers{elements, sizeof(elements)};
    Texture texture1;
    texture1.load_texture(_x, _y ,_z);

    Texture texture2;
    texture2.load_texture(_x+1, _y, _z);

    Texture texture3;
    texture3.load_texture(_x+1, _y+1, _z);

    Texture texture4;
    texture4.load_texture(_x, _y+1, _z);

    while (!glfwWindowShouldClose(window)) {
        int w_width, w_height;
        glfwGetFramebufferSize(window, &w_width, &w_height);
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader_program);
        texture1.bind(0);
        texture2.bind(1);
        texture3.bind(2);
        texture4.bind(3);

        vao.bind();

        // Draw a rectangle from the 8 triangles using 24 indices
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::run() {

}

