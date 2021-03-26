#include "Shader.h"
#include <iostream>
#include <fstream>

Shader::Shader(const GLchar* vertex_source, const GLchar* fragment_source) {
    _vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(_vertex_shader, 1, &vertex_source, NULL);
    glCompileShader(_vertex_shader);

    _fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(_fragment_shader, 1, &fragment_source, NULL);
    glCompileShader(_fragment_shader);


    link_shaders();
}

Shader::~Shader() {
    glDeleteProgram(shader_program);
    glDeleteShader(_fragment_shader);
    glDeleteShader(_vertex_shader);
    std::cout << "Deleted shader" << std::endl;
}

void Shader::link_shaders() noexcept {
    shader_program = glCreateProgram();
    glAttachShader(shader_program, _vertex_shader);
    glAttachShader(shader_program, _fragment_shader);
    glBindFragDataLocation(shader_program, 0, "outColor");
    glLinkProgram(shader_program);
}

void Shader::bind() const noexcept {
    glUseProgram(_id);
}

void Shader::unbind() const noexcept {
    glUseProgram(0);
}

GLuint Shader::get_shader_program() const noexcept {
    return shader_program;
}
