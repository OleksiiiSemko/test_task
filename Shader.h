#ifndef PANGEA_SHADER_H
#define PANGEA_SHADER_H
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


class Shader {
public:
    Shader(const GLchar* vertex_source, const GLchar* fragment_source);
    virtual ~Shader();

    void bind() const noexcept;
    void unbind() const noexcept;
    void link_shaders() noexcept;

    GLuint get_shader_program() const noexcept;

private:
    GLuint _vertex_shader;
    GLuint _fragment_shader;
    GLuint _id;
    GLuint shader_program;
};


#endif //PANGEA_SHADER_H
