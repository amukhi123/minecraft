#pragma once

#include "util/types.h"

namespace VertexAttributeInformation 
{
	namespace Vertex
	{
		constexpr uint8 SIZE {3};
	}

	namespace Texture
	{
		constexpr uint8 SIZE {2};
	}

	constexpr uint8 TOTAL_SIZE {Vertex::SIZE + Texture::SIZE};
}
