#pragma once

#include <string>
#include <memory>

#include <stb/stb_image.h>

#include "util/types.h"

class Image
{
public:
	explicit Image(const std::string& ImageFilePath);

	int Width() const
	{
		return m_Width;
	}

	int Height() const
	{
		return m_Height;
	}

	int NumColourChannels() const
	{
		return m_NumColourChannels;
	}

	uchar8* Data() const
	{
		return m_Data.get();
	}

	
private:
	int m_Width;
	int m_Height;
	int m_NumColourChannels;

	std::unique_ptr<uchar8, decltype(&stbi_image_free)> m_Data;
};

