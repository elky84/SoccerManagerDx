#include "stdafx.h"
#include "SHGame.h"

#include "SHSquad.h"
#include "SHMap.h"
#include "SHCorps.h"

#include "SHTurn.h"
#include "SHCard.h"
#include "SHAction.h"
#include "SHDecide.h"

namespace SH
{

Game::Game()
    : m_Ball(new Ball)
    , m_Turn(new Turn)
    , m_vectorCorps(new VECTOR_CORPS)
    , m_vectorSquad(new VECTOR_SQUAD)
{
	m_Ball->SetPosition(light::POSITION_FLOAT(Map::WIDTH / 2, Map::HEIGHT / 2));
	m_Turn->SetGame(this);
}

Game::~Game()
{

}

void Game::get_turn()
{
	m_Turn->DecideTurn();
	m_Turn->ActionTurn();
}

void Game::Add(const WEAK_SQUAD squad)
{
	m_vectorSquad->push_back(squad);
}

void Game::Add(const WEAK_CORPS corps)
{
	m_vectorCorps->push_back(corps);
}

} // namespace SH