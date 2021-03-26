#ifndef PANGEA_ELEMENTBUFFERS_H
#define PANGEA_ELEMENTBUFFERS_H
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


class ElementBuffers {
public:
    ElementBuffers(const GLuint*, GLuint);
    ~ElementBuffers();

    void bind() const noexcept;
    void unbind() const noexcept;
private:
    GLuint _id;
};


#endif //PANGEA_ELEMENTBUFFERS_H
