#pragma once

#include "Singleton.h"
#include "SHGame.h"

namespace SH
{

class GameManager : public light::Singleton<GameManager>
{
public:
    GameManager();
    ~GameManager();

	WEAK_GAME GetGame()
	{
		return m_Game;
	}

	void AddPlayer(const SHARED_PLAYER player);

	WEAK_PLAYER GetPlayer(TEAM::type teamtype);

private:
	UNIQUE_GAME m_Game;

	std::vector<SHARED_PLAYER> m_vectorPlayer;
};

} // namespace SH