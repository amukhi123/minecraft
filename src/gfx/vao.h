#pragma once

#include "util/types.h"

class Vao
{
public:
	Vao();

	~Vao();

	inline uint32 Id() const
	{
		return m_Id;
	}

	void Draw() const;

	void Bind() const;
private:
	void Setup();

	uint32 m_Id;
};
