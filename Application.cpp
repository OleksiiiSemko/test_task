#include "Application.h"
#include <cmath>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

Application::Application(GLFWwindow* window, const char* vertex_source, const char* fragment_source)
        : _window{window}, _shader{vertex_source, fragment_source}
        {
            _init();
            _load_all_textures();
        }

Application::~Application() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Application::_init() {
    _shader.bind();

    _vaos.emplace_back(new VertexArray{});
    _vbos.emplace_back(new VertexBuffer{vertices1, sizeof(vertices1)});
    ebo.bind();
    _vaos[0]->specify_layout();

    _vaos.emplace_back(new VertexArray{});
    _vbos.emplace_back(new VertexBuffer{vertices2, sizeof(vertices2)});
    ebo.bind();
    _vaos[1]->specify_layout();

    _vaos.emplace_back(new VertexArray{});
    _vbos.emplace_back(new VertexBuffer{vertices3, sizeof(vertices3)});
    ebo.bind();
    _vaos[2]->specify_layout();

    _vaos.emplace_back(new VertexArray{});
    _vbos.emplace_back(new VertexBuffer{vertices4, sizeof(vertices4)});
    ebo.bind();
    _vaos[3]->specify_layout();

    _texs.emplace_back(new Texture{});
    _texs.emplace_back(new Texture{});
    _texs.emplace_back(new Texture{});
    _texs.emplace_back(new Texture{});
}

void Application::zoom() {
    _x = _x + std::pow(2, _z-1);
    _y = _y + std::pow(2, _z-1);
    _z += 1;

    _load_all_textures();
}

void Application::unzoom() {
    if (_z > 1) {
        _z -= 1;
        _x = _x - std::pow(2, _z - 1);
        _y -= _y - std::pow(2, _z - 1);

        _load_all_textures();
    }
}

void Application::move_north() {
    if (_y > 0) {
        _y--;
        _load_all_textures();
    }
}

void Application::move_south() {
    if (_y < std::pow(2, _z - 1)) {
        _y++;
        _load_all_textures();
    }
}

void Application::move_west() {
    if (_x > 0) {
        _x--;
        _load_all_textures();
    }
}

void Application::move_east() {
    if (_x < std::pow(2, _z) - 2) {
        _x++;
        _load_all_textures();
    }
}

void Application::_load_all_textures() {
    _texs[0]->bind(0);
    _texs[0]->load_texture(_load_image(), width, height);
    _x++;
    _texs[1]->bind(1);
    _texs[1]->load_texture(_load_image(), width, height);
    _y++;
    _texs[2]->bind(2);
    _texs[2]->load_texture(_load_image(), width, height);
    _x--;
    _texs[3]->bind(3);
    _texs[3]->load_texture(_load_image(), width, height);
    _y--;
}

unsigned char* Application::_load_image() {
    std::ostringstream filename;
    filename << "../Textures/" << _x << _y << _z << ".png";
    unsigned char *image = SOIL_load_image(filename.str().c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    if (!image) {
        _download_image(filename.str());
        image = SOIL_load_image(filename.str().c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    }

    return image;
}

void Application::_download_image(const std::string& filename) noexcept {
    std::fstream fs;
    std::ostringstream url_stream;
    url_stream << "https://api.mapbox.com/styles/v1/mapbox/streets-v11/tiles/512/" <<\
    _z << "/" << _x << "/" << _y << "/?access_token=pk.eyJ1IjoidmFnMW5hIiwiYSI6ImNrbTgwemJodzEzdWcyd254ZWZ1czdrbTQifQ.mcHqUTS2rBhZBN_ZAakxjg";
    fs.open(filename, std::ios::binary | std::ios::out | std::ios::trunc);
    fs << curlpp::options::Url(url_stream.str());
    fs.close();
}

void Application::render() {
    _shader.bind();
    _load_all_textures();

    while (!glfwWindowShouldClose(_window)) {
        int w_width, w_height;
        glfwGetFramebufferSize(_window, &w_width, &w_height);
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (int i = 0; i < _vaos.size(); i++) {
            _vaos[i]->bind();
            _texs[i]->bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        }

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

unsigned int Application::_x{0};
unsigned int Application::_y{0};
unsigned int Application::_z{1};

std::vector<std::unique_ptr<Texture>> Application::_texs;

int Application::width;
int Application::height;
