#include <glad/gl.h>

#include <iostream>

#include "shader_program.h"

ShaderProgram::ShaderProgram() : m_Id {glCreateProgram()}
{
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(Id());
}

void ShaderProgram::AttachShader(const int& Shader) const
{
	glAttachShader(Id(), Shader);
}

void ShaderProgram::Link() const
{
	glLinkProgram(Id());

	int linkSuccessful {};

	glGetProgramiv(Id(), GL_LINK_STATUS, &linkSuccessful);

	if (!linkSuccessful)
	{
		char log[512];

		std::cout << "Linking shader program failed: " << log << std::endl;	
	}
}

void ShaderProgram::Use() const
{
	glUseProgram(Id());
}
