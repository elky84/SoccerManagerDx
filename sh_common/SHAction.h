#pragma once

#include "SHTypeDefinition.h"

#include <vector>

#include "SHDecide.h"

namespace SH
{

class Action
{
public:
	Action();
	~Action();

	DecideAction::Type GetType() const
	{
		return m_Type;
	}

	WEAK_CARD GetCard() const
	{
		return m_Card;
	}

	void SetGame(WEAK_GAME game)
	{
		m_Game = game;
	}

	void Set(DecideAction::Type type, WEAK_CARD card, WEAK_CARD target);

	bool Update();

	bool Move();

private:
	WEAK_GAME m_Game;

	DecideAction::Type m_Type;

	WEAK_CARD m_Card;

	WEAK_CARD m_Target;
};

} // namespace SH