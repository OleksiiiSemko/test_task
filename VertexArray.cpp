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

void VertexArray::specify_layout() const noexcept {
    // Specify vertex buffer layout
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

    // Specify texture layout
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (const void*)(2 * sizeof(GLfloat)));
}

const GLuint VertexArray::get_id() const noexcept {
    return _id;
}
