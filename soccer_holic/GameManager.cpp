#include "stdafx.h"
#include "GameManager.h"

#include "SHMap.h"
#include "SHPlayer.h"

namespace SH
{

GameManager::GameManager()
    : m_Game(new Game)
{

}

GameManager::~GameManager()
{

}

void GameManager::AddPlayer(const SHARED_PLAYER player)
{
	m_vectorPlayer.push_back(player);
}

WEAK_PLAYER GameManager::GetPlayer(TEAM::type teamtype)
{
	return m_vectorPlayer[teamtype];
}

} // namespace SH