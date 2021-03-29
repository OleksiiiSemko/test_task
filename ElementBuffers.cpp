#include "ElementBuffers.h"
#include <iostream>

ElementBuffers::ElementBuffers(const GLuint* elements, GLuint size) {
    glGenBuffers(1, &_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, elements, GL_STATIC_DRAW);
}

ElementBuffers::~ElementBuffers() {
    glDeleteBuffers(1, &_id);
    std::cout << "Deleted element buffer" << std::endl;
}

void ElementBuffers::bind() const noexcept {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
}

void ElementBuffers::unbind() const noexcept {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
