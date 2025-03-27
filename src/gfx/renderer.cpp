#define GLAD_GL_IMPLEMENTATION

#include <glad/gl.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "util/input.h"

#include "renderer.h"
#include "gfx/colour.h"
#include "gfx/shader.h"
#include "gfx/shader_program.h"
#include "gfx/vbo.h"
#include "gfx/vao.h"
#include "gfx/texture.h"

Renderer::Renderer(const uint16& Height, const uint16& Width) : m_Window {Height, Width}
{
}

Renderer::~Renderer()
{
	glfwTerminate();
}

bool Renderer::Init()
{
	return  m_Window.CreateWindow() && InitGlad();
}

void Renderer::Render()
{
	glViewport(0, 0, m_Window.Width(), m_Window.Height());

	Shader vertexShader {GL_VERTEX_SHADER, "default.vert"};
	Shader fragmentShader {GL_FRAGMENT_SHADER, "default.frag"};

	ShaderProgram shaderProgram {};

	shaderProgram.AttachShader(vertexShader.Id());
	shaderProgram.AttachShader(fragmentShader.Id());

	shaderProgram.Link();

	Input input {};

	Vao vao {};

	Vbo vbo {};

	vao.Bind();
    vbo.Bind();

	vao.Setup();

	Texture texture {"dirt.png"};

	while (!m_Window.ShouldWindowClose())
	{
		input.ProcessInput(m_Window);

		constexpr Colour GRAY {0.5f, 0.5f, 0.5f, 1.0f};

		glClearColor(GRAY.r, GRAY.g, GRAY.b, GRAY.a);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Use();

		vao.Bind();
		vao.Draw();

		glfwSwapBuffers(m_Window.WindowPtr());
		glfwPollEvents();
	}
}

bool Renderer::InitGlad() const
{
	if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;	

		return false;
	}

	return true;
}
