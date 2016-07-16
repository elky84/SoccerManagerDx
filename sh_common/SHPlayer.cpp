#include "stdafx.h"
#include "SHPlayer.h"

#include "MetaData.h"
#include "SHCard.h"
#include "SHSquad.h"
#include "SHCorps.h"

#include <algorithm>

namespace SH
{

Player::Player()
    : m_Corps(new Corps)
    , m_Squad(new Squad)
{

}

Player::~Player()
{

}

void Player::AddCard(Card* card)
{
	m_vectorCard.push_back(SHARED_CARD(card));
}

WEAK_CARD Player::PickCard()
{
	return m_vectorCard[rand() % m_vectorCard.size()];
}

void Player::PickCorps()
{
	while(m_Corps->VectorCard().size() != MAX_CORPS_CARD)
	{
		WEAK_CARD Card = m_vectorCard[rand() % m_vectorCard.size()];
		if(m_Corps->isExist(Card) == false)
		{
			m_Corps->AddCard(Card);
		}
	}
}

void Player::PickSquad(TEAM::type team)
{
	while(m_Squad->MapCard().size() != MAX_SQUAD_CARD)
	{
		WEAK_CARD card = m_vectorCard[rand() % m_vectorCard.size()];
		if(m_Squad->isExist(card) == false)
		{
			m_Squad->AddCard(card);
			if(team == TEAM::RED)
				card->SetPosition(RedPosition[m_Squad->MapCard().size() - 1]);
			else
				card->SetPosition(BluePosition[m_Squad->MapCard().size() - 1]);
		}

	}
}

bool Player::isExist(const WEAK_CARD& card)
{
	for each(WEAK_CARD check in m_vectorCard)
	{
		if(check->GetCharacter()->Index() == card->GetCharacter()->Index())
		{
			return true;
		}
	}
	return false;
}

} // namespace SH