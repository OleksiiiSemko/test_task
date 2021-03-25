#ifndef PANGEA_SHADER_H
#define PANGEA_SHADER_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Shader {
public:
    Shader() = default;
    virtual ~Shader();

    void compile_vertex_shader(const GLchar*) const noexcept;
    void compile_fragment_shader(const GLchar*) const noexcept;
    void link_shaders() const noexcept;
    void specify_layout() const noexcept;
private:
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint shader_program = glCreateProgram();
};


#endif //PANGEA_SHADER_H
