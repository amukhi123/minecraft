#pragma once

#include <util/types.h>

class ShaderProgram
{
public:
	ShaderProgram();

	~ShaderProgram();

	void AttachShader(const int& Shader) const;

	void Link() const;

	void Use() const;

	inline uint32 Id() const
	{
		return m_Id;
	}
private:
	uint32 m_Id;	
};
