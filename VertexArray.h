#ifndef PANGEA_VERTEXARRAY_H
#define PANGEA_VERTEXARRAY_H
#include <glad/glad.h>

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void bind() const noexcept;
    void unbind() const noexcept;
private:
    GLuint _id;
};


#endif //PANGEA_VERTEXARRAY_H
