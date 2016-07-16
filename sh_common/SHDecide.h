#pragma once

#include "SHTypeDefinition.h"

/*
	��� ������ ĳ������ ���ݰŸ�(�̵� �� ���� ��Ÿ����� ��ģ)�ȿ� ���� ������ �˻��մϴ�.

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