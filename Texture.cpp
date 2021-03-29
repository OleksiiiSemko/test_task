#include "Texture.h"
#include <iostream>
#include <fstream>

Texture::Texture() {
    glGenTextures(1, &_id);
    glBindTexture(GL_TEXTURE_2D, _id);
}

Texture::~Texture() {
    glDeleteTextures(1, &_id);
    std::cout << "Deleted texture" << std::endl;
}

void Texture::bind(GLuint slot) const noexcept {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, _id);
}

void Texture::unbind() const noexcept {
    glBindTexture(GL_TEXTURE_2D, _id);
}

void Texture::load_texture(unsigned char* image, int width, int height) {

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
