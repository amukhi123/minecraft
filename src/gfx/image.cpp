#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif

#include "util/types.h"
#include "gfx/image.h"

Image::Image(const std::string& ImageFilePath) : m_Width {}, m_Height {}, m_NumColourChannels {}, m_Data {stbi_load(ImageFilePath.c_str(), &m_Width, &m_Height, &m_NumColourChannels, 0), &stbi_image_free}
{
}

