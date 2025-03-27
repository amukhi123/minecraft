#pragma once

#include <vector>

#include "util/types.h"

class Vbo
{
public:
	Vbo();

	virtual ~Vbo();

	uint32 Id() const
	{
		return m_Id;
	}

	void Bind();
private:
	uint32 m_Id;	

	std::vector<float> m_VertexData;

	void Setup();

	void CreateVertexData();
};
