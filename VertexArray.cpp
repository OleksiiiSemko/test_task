#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &_id);
    glBindVertexArray(_id);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &_id);
}

void VertexArray::bind() const noexcept {
    glBindVertexArray(_id);
}

void VertexArray::unbind() const noexcept {
    glBindVertexArray(0);
}
