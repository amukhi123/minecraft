#include <glad/gl.h>

#include "gfx/vbo.h"
#include "gfx/vertex_attribute_information.h"

Vbo::Vbo() : m_Id {}, m_VertexData {}
{
	Setup();
}

void Vbo::Setup()
{
	glGenBuffers(1, &m_Id);

	CreateVertexData();
}

void Vbo::CreateVertexData()
{
	const std::vector<float> verticies {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
	const std::vector<float> textureCoords {0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f};

	for (uint8 i {0}; i < VertexAttributeInformation::Vertex::SIZE; ++i)
	{
		for (uint8 j {0}; j < VertexAttributeInformation::Vertex::SIZE; ++j)
		{
			m_VertexData.push_back(verticies[i * VertexAttributeInformation::Vertex::SIZE + j]);
		}

		for (uint8 j1 {0}; j1 < VertexAttributeInformation::Texture::SIZE; ++j1)
		{
			m_VertexData.push_back(textureCoords[i * VertexAttributeInformation::Texture::SIZE + j1]);
		}
	}
}

void Vbo::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, Id());

	glBufferData(GL_ARRAY_BUFFER, m_VertexData.size() * sizeof(float), m_VertexData.data(), GL_STATIC_DRAW);
}

Vbo::~Vbo()
{
	glDeleteBuffers(1, &m_Id);
}
