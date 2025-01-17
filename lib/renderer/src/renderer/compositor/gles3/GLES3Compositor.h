#ifndef OPENGLCORERENDERER_H
#define OPENGLCORERENDERER_H

#include <memory>

#include "../AbstractCompositor.h"
#include "../../ResourceStorage.h"
#include <glad/glad.h>

namespace renderer::compositor::gles3 {
	// PIMPL;
	class GLES3Texture;
	class Shader;
	class QuadVertexArray;
    typedef void* (*gl_functor)(const char*) ;

	class GLES3Compositor: public AbstractCompositor
	{
	public:
        GLES3Compositor(int32_t screen_width, int32_t screen_height, GLADloadproc loadproc);
		~GLES3Compositor();
		Texture texture_create(int32_t width, int32_t height, TextureType texture_type, BlendMode blend_mode);
		void texture_set_data(Texture texture, uint8_t* data);
		void texture_render(Texture texture, const Rect& src_rect, const Rect& dst_rect);
		void texture_destroy(Texture texture);
		void texture_query(Texture texture, int32_t* width, int32_t* height, TextureType* texture_type, BlendMode* blend_mode);
		void texture_set_color(Texture texture, const Color& color);
		void render_begin(bool clearColorBuffer);
		void render_present();
		void initialize();
		void dispose();
		void query_output_size(int32_t* width, int32_t* height);
		void set_resolution(int32_t width, int32_t height);
		void set_viewport(const Rect& viewport);
		void get_offset(float &x, float &y);
		void get_scale(float &x, float &y);
		void set_offset(float x, float y);
		void set_scale(float x, float y);
		void read_pixels(uint8_t* output);
	private:
        int32_t _width;
		int32_t _height;
		Rect _viewport;
		float _offsetX;
		float _offsetY;
		float _scaleX;
		float _scaleY;

		renderer::ResourceStorage<Texture, GLES3Texture> _texture_storage;

		std::unique_ptr<Shader> _texture_shader;
		std::unique_ptr<QuadVertexArray> _vertex_array;

		int32_t _previous_vao;


	};
}

#endif // OPENGLCORERENDERER_H

