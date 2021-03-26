#include "Texture.h"
#include <iostream>
#include <SOIL/SOIL.h>
#include <fstream>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

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

void Texture::load_texture(unsigned int x, unsigned int y, unsigned int z) {
    int width, height;
    std::ostringstream filename;
    filename << "../Textures/" << x << y << z << ".png";
    unsigned char *image = SOIL_load_image(filename.str().c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    /*if (!image) {
        _download_image(filename.str(), x, y, z);
        image = SOIL_load_image(filename.str().c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    }*/

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    SOIL_free_image_data(image);
}

/*void Texture::_download_image(const std::string& filename, unsigned int x, unsigned int y, unsigned int z) {
    std::fstream fs;
    std::ostringstream url_stream;
    url_stream << "https://api.mapbox.com/styles/v1/mapbox/streets-v11/tiles/512/" <<\
    z << "/" << x << "/" << y << "/?access_token=pk.eyJ1IjoidmFnMW5hIiwiYSI6ImNrbTgwemJodzEzdWcyd254ZWZ1czdrbTQifQ.mcHqUTS2rBhZBN_ZAakxjg";
    fs.open(filename, std::ios::binary | std::ios::out | std::ios::trunc);
    fs << curlpp::options::Url(url_stream.str());
    fs.close();
}*/
