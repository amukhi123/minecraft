#pragma once

#include <string>

#include "util/types.h"

class Shader
{
public:
	Shader(const int& Type, const std::string& ShaderName);

	virtual ~Shader();

	inline uint32 Id() const
	{
		return m_Id;
	}

	uint32 CreateShader(const int& Type) const;

	void CompileShader(const std::string& Path) const;

	std::string Source(const std::string& Path) const;
private:
	uint32 m_Id;	
};
