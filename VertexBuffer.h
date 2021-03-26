#ifndef PANGEA_VERTEXBUFFER_H
#define PANGEA_VERTEXBUFFER_H
#include <glad/glad.h>


class VertexBuffer {
public:
    VertexBuffer(const GLfloat*, GLuint);
    ~VertexBuffer();

    void bind() const noexcept;
    void unbind() const noexcept;
private:
    GLuint _id;
};


#endif //PANGEA_VERTEXBUFFER_H
