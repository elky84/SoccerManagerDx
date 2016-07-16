#pragma once

#include "SHTypeDefinition.h"

#include <vector>

namespace SH
{

class Turn
{
public:
	Turn();
	~Turn();

	void DecideTurn();
	void ActionTurn();

	void SetGame(WEAK_GAME game);

private:
	UNIQUE_DECIDE m_Decide;

	WEAK_GAME m_Game;

	std::vector<WEAK_CARD> m_vectorCard;

	std::vector<SHARED_ACTION> m_vectorAction;
};

} // namespace SH