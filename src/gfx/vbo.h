#pragma once

#include <vector>

#include "util/types.h"

class Vbo
{
public:
	Vbo();

	virtual ~Vbo();

	inline uint32 Id() const
	{
		return m_Id;
	}

	void Bind();
private:
	uint32 m_Id;	

	std::vector<float> m_Verticies;

	void Setup();
};
