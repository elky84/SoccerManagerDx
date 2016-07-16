#pragma once

#include "SHTypeDefinition.h"
#include <vector>

namespace SH
{

class Map
{
public:
	static const int WIDTH = 1920;
	static const int HEIGHT = 640;

public:
	Map();
	~Map();

public:
	void SetSquad(const WEAK_VECTOR_SQUAD vectorSquad)
	{
		m_vectorSquad = vectorSquad;
	}

private:
	WEAK_VECTOR_SQUAD m_vectorSquad;
};

} // namespace SH