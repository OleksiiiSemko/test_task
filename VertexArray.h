#ifndef PANGEA_VERTEXARRAY_H
#define PANGEA_VERTEXARRAY_H
#include "VertexBuffer.h"
#include "Texture.h"
#include "Shader.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void bind() const noexcept;
    void unbind() const noexcept;

    void specify_layout(GLuint, const GLuint) const noexcept;
    const GLuint get_id() const noexcept;
private:
    GLuint _id;
};

#endif //PANGEA_VERTEXARRAY_H
