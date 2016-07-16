#pragma once

#include "SHTypeDefinition.h"

#include "SHBall.h"

#include <vector>

namespace SH
{

class Game
{
public:
	static const int MAX_TEAM = 2;

public:
	Game();
	~Game();

public:
	WEAK_MAP GetMap()
	{
		return m_Map;
	}

	void get_turn();

	void Add(const WEAK_SQUAD squad);

	void Add(const WEAK_CORPS corps);

	VECTOR_SQUAD& VectorSquad()
	{
		return *m_vectorSquad.get();
	}

	VECTOR_CORPS& VectorCorps()
	{
		return *m_vectorCorps.get();
	}

	WEAK_BALL GetBall()
	{
		return m_Ball;
	}

private:
	UNIQUE_BALL m_Ball;

	UNIQUE_TURN m_Turn;

	UNIQUE_MAP m_Map;

	UNIQUE_VECTOR_SQUAD m_vectorSquad;

	UNIQUE_VECTOR_CORPS m_vectorCorps;
};

} // namespace SH