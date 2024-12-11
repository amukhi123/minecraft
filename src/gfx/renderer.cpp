#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "renderer.h"
#include "util/input.h"
#include "gfx/colour.h"

Renderer::Renderer(const uint16& Height, const uint16& Width) : m_Window {Height, Width}
{
}

bool Renderer::Init()
{
	return  m_Window.CreateWindow() && InitGlad();
}

void Renderer::Render()
{
	glViewport(0, 0, m_Window.Width(), m_Window.Height());

	Input input {};

	while (!m_Window.ShouldWindowClose())
	{
		constexpr Colour GRAY {0.5f, 0.5f, 0.5f, 1.0f};

		glClearColor(GRAY.r, GRAY.g, GRAY.b, GRAY.a);
		glClear(GL_COLOR_BUFFER_BIT);

		input.ProcessInput(m_Window);

		glfwSwapBuffers(m_Window.WindowPtr());
		glfwPollEvents();
	}
}

bool Renderer::InitGlad() const
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;	

		return false;
	}

	return true;
}
