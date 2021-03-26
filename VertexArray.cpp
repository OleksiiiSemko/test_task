#include "VertexArray.h"
#include <iostream>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &_id);
    glBindVertexArray(_id);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &_id);
    std::cout << "delete vao" << std::endl;
}

void VertexArray::bind() const noexcept {
    glBindVertexArray(_id);
}

void VertexArray::unbind() const noexcept {
    glBindVertexArray(0);
}

void VertexArray::specify_layout(GLuint shader_program, const GLuint id) const noexcept {
    // Specify vertex buffer layout
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);

    // Specify color layout
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

    // Specify texture layout
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));

    //Specify texture layout
    glEnableVertexAttribArray(3);
    glad_glVertexAttribPointer(3, 1, GL_FLAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(7 * sizeof(GLfloat)));
}

const GLuint VertexArray::get_id() const noexcept {
    return _id;
}
