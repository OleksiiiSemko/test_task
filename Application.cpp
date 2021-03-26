#include "Application.h"
#include <sstream>

Application::Application(GLFWwindow* window_) : shader{vertex_source,fragment_source},
                             ebo{elements, sizeof(elements)},
                             window{window_}
                             {
    _render();
}

Application::~Application() {
    glfwDestroyWindow(window);
    glfwTerminate();
}



void Application::_render() {
    Shader shader1{vertex_source, fragment_source};
    VertexArray vao;
    VertexBuffer vbo{vertices, sizeof(vertices)};
    vao.specify_layout(shader1.get_shader_program(), vbo.get_id());

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
        shader1.bind();
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

