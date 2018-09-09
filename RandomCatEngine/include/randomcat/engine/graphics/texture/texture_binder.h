#pragma once

#include <GL/glew.h>

#include <randomcat/engine/graphics/texture/detail/texture_raii.h>
#include <randomcat/engine/graphics/texture/texture_manager.h>

namespace randomcat::engine::graphics::texture {
    struct texture_array {
        detail::texture_id id;
        int width;
        int height;
        int layers;
    };

    texture_array genTextureArray(int _width, int _height, int _layers) {
        detail::texture_id id;
        glBindTexture(GL_TEXTURE_2D_ARRAY, id);
        glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, _width, _height, _layers);

        return {id, _width, _height, _layers};
    }

    void bindTexture(texture_array const& _array, int _layer, texture const& _texture) {
        //        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glBindTexture(GL_TEXTURE_2D_ARRAY, _array.id);
        glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, _layer, _texture.width(), _texture.height(), 1, GL_RGBA, GL_UNSIGNED_BYTE, _texture.data());
    }
}    // namespace randomcat::engine::graphics::texture
