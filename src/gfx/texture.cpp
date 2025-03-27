#include <glad/gl.h>

#include "util/project_file_system.h"

#include "gfx/texture.h"
#include "gfx/image.h"

Texture::Texture(const std::string& FileName) : m_Id {}, m_TextureCoordinates {0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f}, m_Image {ProjectFileSystem::Instance()->GetTextureFilePath(FileName).string()}
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenTextures(1, &m_Id);

	glBindTexture(GL_TEXTURE_2D, m_Id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Image.Width(), m_Image.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, m_Image.Data());

	glGenerateMipmap(GL_TEXTURE_2D);
}
