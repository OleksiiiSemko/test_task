#ifndef PANGEA_TEXTURE_H
#define PANGEA_TEXTURE_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <SOIL/SOIL.h>
#include <string>

#include "3rdparty/glfw/deps/linmath.h"

class Texture {
public:
    Texture();
    ~Texture();

    void bind(GLuint slot = 0) const noexcept;
    void unbind() const noexcept;

    void load_texture(unsigned int, unsigned int, unsigned int);
private:
    /*void _download_image(const std::string&, unsigned int, unsigned int, unsigned int);*/

    GLuint _id;
};


#endif //PANGEA_TEXTURE_H
