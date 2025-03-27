#pragma once

#include "util/types.h"

class VertexAttribute
{
public:
	VertexAttribute(const uint8& Size, const uint8& Stride, const uint8& Offet);

	void* OffsetAsVoidPointer() const
	{
		return reinterpret_cast<void*>(m_Offset);
	}

	uint8 Index() const
	{
		return m_Index;
	}

	uint8 Size() const
	{
		return m_Size;
	}

	uint8 Stride() const 
	{
		return m_Stride;
	}
private:
	static uint8 s_Index;

	uint8 m_Index;
	uint8 m_Size;	
	uint8 m_Stride;
	uint8 m_Offset;
};

inline uint8 VertexAttribute::s_Index {0};
