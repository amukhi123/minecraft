#pragma once

#include <memory>

#include "util/types.h"

struct GLFWwindow;

class Window
{
public:
	Window(const uint16& Height, const uint16& Width);

	virtual ~Window();

	inline uint16 Height() const
	{
		return m_Height;
	}

	inline uint16 Width() const
	{
		return m_Width;
	}

	bool ShouldWindowClose() const;

	void CloseWindow() const;

	GLFWwindow* WindowPtr() const;

	bool CreateWindow();
private:
	uint16 m_Height;
	uint16 m_Width;

	std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> m_Window;

	static void OnResizeWindow(GLFWwindow* Window, int Width, int Height);

	void RegisterCallbacks();
};
