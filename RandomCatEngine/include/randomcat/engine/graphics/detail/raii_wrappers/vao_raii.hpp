#pragma once

#include <GL/glew.h>

#include <randomcat/engine/graphics/detail/raii_wrappers/opengl_raii_id.hpp>

namespace randomcat::engine::graphics::detail {
    inline decltype(auto) makeVAO() noexcept {
        unsigned id;
        glGenVertexArrays(1, &id);
        return opengl_raw_id{id};
    }

    inline void destroyVAO(opengl_raw_id _id) noexcept { glDeleteVertexArrays(1, &_id); }

    using vao_id = opengl_raii_id<makeVAO, destroyVAO>;
}    // namespace randomcat::engine::graphics::detail