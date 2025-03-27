#pragma once

#include "util/types.h"

class Vao
{
public:
	Vao();

	~Vao();

	uint32 Id() const
	{
		return m_Id;
	}

	void Draw() const;

	void Bind() const;

	void Gen();

	void Setup();
private:
	uint32 m_Id;
};
