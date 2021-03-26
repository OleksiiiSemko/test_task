#ifndef PANGEA_TEXTURE_H
#define PANGEA_TEXTURE_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <SOIL/SOIL.h>


class Texture {
public:
    void create_texture();
    void load_texture(unsigned char*);
private:
    static int img_width, img_height;
    GLuint tex;
};


#endif //PANGEA_TEXTURE_H
