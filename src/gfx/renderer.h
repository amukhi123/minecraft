#pragma once

#include "window.h"
#include "util/types.h"

class Renderer
{
public:
	Renderer(const uint16& Height, const uint16& Width);

	virtual ~Renderer();

	bool Init();

	void Render();
private:
	Window m_Window;

	bool InitGlad() const;
};
