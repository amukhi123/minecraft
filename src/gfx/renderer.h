#pragma once

#include "Window.h"
#include "util/types.h"

class Renderer
{
public:
	Renderer(const uint16& Height, const uint16& Width);

	bool Init();

	void Render();
private:
	Window m_Window;

	bool InitGlad() const;
};
