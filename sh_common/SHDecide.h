#pragma once

#include "SHTypeDefinition.h"

/*
	모든 오더는 캐릭터의 공격거리(이동 후 공격 사거리까지 합친)안에 들어온 적만을 검색합니다.

*/

namespace SH
{

class Decide
{
public:

public:
	Decide();
	~Decide();

	bool Select(WEAK_CARD card);

    Action* SelectAction(WEAK_CARD card);

	WEAK_CARD SelectTarget(WEAK_CARD card);

	void SetGame(WEAK_GAME game)
	{
		m_Game = game;
	}

private:
	WEAK_GAME m_Game;
};

} // namespace SH