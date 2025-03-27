#include <glad/gl.h>

#include "gfx/vao.h"
#include "gfx/vertex_attribute.h"
#include "gfx/vertex_attribute_information.h"

Vao::Vao() : m_Id {}
{
	Gen();
}

Vao::~Vao()
{
	glDeleteBuffers(1, &m_Id);
}
	
void Vao::Draw() const
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Vao::Gen()
{
	glGenVertexArrays(1, &m_Id);
}

void Vao::Setup()
{
	constexpr uint16 STRIDE {VertexAttributeInformation::TOTAL_SIZE * sizeof(float)};

	const VertexAttribute vertex {VertexAttributeInformation::Vertex::SIZE, STRIDE, 0};
	const VertexAttribute texture {VertexAttributeInformation::Texture::SIZE, STRIDE, VertexAttributeInformation::Vertex::SIZE * sizeof(float)};

	glVertexAttribPointer(vertex.Index(), vertex.Size(), GL_FLOAT, GL_FALSE, STRIDE, vertex.OffsetAsVoidPointer());
	glEnableVertexAttribArray(vertex.Index());

	glVertexAttribPointer(texture.Index(), texture.Size(), GL_FLOAT, GL_FALSE, STRIDE, texture.OffsetAsVoidPointer());
	glEnableVertexAttribArray(texture.Index());
}

void Vao::Bind() const
{
	glBindVertexArray(Id());
}
