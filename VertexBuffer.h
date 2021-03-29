#ifndef PANGEA_VERTEXBUFFER_H
#define PANGEA_VERTEXBUFFER_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>


class VertexBuffer {
public:
    VertexBuffer(const GLfloat*, GLuint);
    ~VertexBuffer();

    void bind() const noexcept;
    void unbind() const noexcept;

    const GLuint get_id() const noexcept;
private:
    GLuint _id;
};


#endif //PANGEA_VERTEXBUFFER_H
