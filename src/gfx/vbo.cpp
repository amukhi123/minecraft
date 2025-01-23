#include <glad/gl.h>
#include <iostream>

#include "vbo.h"

Vbo::Vbo() : m_Id {}, m_Verticies {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f}
{
	Setup();
}

void Vbo::Setup()
{
	glGenBuffers(1, &m_Id);
}

void Vbo::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, Id());

	glBufferData(GL_ARRAY_BUFFER, m_Verticies.size() * sizeof(float), m_Verticies.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);

	glEnableVertexAttribArray(0);
}

Vbo::~Vbo()
{
	glDeleteBuffers(1, &m_Id);
}
