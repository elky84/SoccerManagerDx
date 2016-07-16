#include "stdafx.h"
#include "SHTurn.h"

#include "SHCard.h"
#include "SHAction.h"
#include "SHDecide.h"

#include "SHSquad.h"

#include "SHMap.h"

#include "SHGame.h"

namespace SH
{

Turn::Turn()
    : m_Decide(new Decide)
{

}

Turn::~Turn()
{

}

void Turn::SetGame(WEAK_GAME game)
{
	m_Game = game;
	m_Decide->SetGame(game);
}

void Turn::DecideTurn()
{
	VECTOR_SQUAD& vectorSquad = m_Game->VectorSquad();
	for each( WEAK_SQUAD squad in vectorSquad )
	{
		for each( const Squad::MAP_CARD::value_type val in squad->MapCard() )
		{
			WEAK_CARD card = val.second;

			WEAK_SQUAD RivalSquad = vectorSquad[TEAM::RED]->isExist(card) == false ? vectorSquad[TEAM::RED] : vectorSquad[TEAM::BLUE];
			if( RivalSquad->isAllDie() )
				continue;

			if(card->DecideTiming())
			{
				m_Decide->Select(card);
			}

			if(card->ActionTiming())
			{
				Action* action = m_Decide->SelectAction(card);
				action->SetGame(m_Game);
				m_vectorAction.push_back(SHARED_ACTION(action));
			}

			card->AccumTime();
		}
	}
}

void Turn::ActionTurn()
{
	for each(WEAK_ACTION action in m_vectorAction)
	{
		action->Update();
	}

	m_vectorAction.clear();
}

} // namespace SH