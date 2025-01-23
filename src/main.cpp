#include "gfx/renderer.h"

int main()
{
	Renderer renderer {800, 800};

	if (!renderer.Init())
	{
		return EXIT_SUCCESS;
	}

	renderer.Render();
}
