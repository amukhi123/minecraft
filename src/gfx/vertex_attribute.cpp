#include "vertex_attribute.h"

VertexAttribute::VertexAttribute(const uint8& Size, const uint8& Stride, const uint8& Offet) : m_Index {VertexAttribute::s_Index++}, m_Size {Size}, m_Stride {Stride}, m_Offset {Offet}
{
}
