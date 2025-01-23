#include <glad/gl.h>
#include <iostream>

#include "vao.h"

Vao::Vao() : m_Id {}
{
	Setup();
}

Vao::~Vao()
{
	glDeleteBuffers(1, &m_Id);
}
	
void Vao::Draw() const
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Vao::Setup()
{
	glGenVertexArrays(1, &m_Id);
}

void Vao::Bind() const
{
	glBindVertexArray(Id());
}
