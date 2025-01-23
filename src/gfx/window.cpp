#include <glad/gl.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "window.h"

Window::Window(const uint16& Height, const uint16& Width) : m_Height {Height}, m_Width {Width}, m_Window {nullptr, [](GLFWwindow*){}}
{
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::ShouldWindowClose() const
{
	return glfwWindowShouldClose(WindowPtr());
}

void Window::CloseWindow() const
{
	glfwSetWindowShouldClose(WindowPtr(), true);
}

GLFWwindow* Window::WindowPtr() const
{
	return m_Window.get();
}

bool Window::CreateWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>(glfwCreateWindow(m_Width, m_Height, "Minecraft", nullptr, nullptr), glfwDestroyWindow);

	if (!m_Window)
	{
		std::cout << "Failed to create window" << std::endl;

		return false;
	}

	glfwMakeContextCurrent(WindowPtr());

	RegisterCallbacks();

	return true;
}

void Window::RegisterCallbacks()
{
	glfwSetFramebufferSizeCallback(WindowPtr(), OnResizeWindow);
}

void Window::OnResizeWindow(GLFWwindow* Window, int Width, int Height)
{
	glViewport(0, 0, Width, Height);
}
