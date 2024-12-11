#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "gfx/window.h"

void Input::ProcessInput(const Window& Window)
{
	if (glfwGetKey(Window.WindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		Window.CloseWindow();
	}
}
