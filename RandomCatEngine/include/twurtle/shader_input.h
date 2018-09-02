#pragma once

#include <GL/glew.h>

namespace randomcat::graphics {
    struct shader_input {
        GLuint position;
        GLint count;
        GLenum type;
        GLboolean normalized;
        GLsizei stride;
        void const* offset;
    };
}    // namespace randomcat::graphics
