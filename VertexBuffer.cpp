#include "VertexBuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer(const GLfloat* vertices, GLuint size) {
    glGenBuffers(1, &_id);
    glBindBuffer(GL_ARRAY_BUFFER, _id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &_id);
    std::cout << "delete vbo" << std::endl;
}

void VertexBuffer::bind() const noexcept {
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VertexBuffer::unbind() const noexcept {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const GLuint VertexBuffer::get_id() const noexcept {
    return _id;
}
