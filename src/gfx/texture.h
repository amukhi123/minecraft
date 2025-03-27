#pragma once

#include <vector>
#include <string>

#include "util/types.h"
#include "gfx/image.h"

class Texture
{
public:
	explicit Texture(const std::string& FileName);
private:
	uint32 m_Id;

	std::vector<float> m_TextureCoordinates;

	Image m_Image;

	uint32 Id() const
	{
		return m_Id;
	}
};
