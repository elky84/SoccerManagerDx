#include "stdafx.h"
#include "SHSquad.h"

#include "SHCard.h"

namespace SH
{

Squad::Squad()
{

}

Squad::~Squad()
{

}

void Squad::AddCard(const WEAK_CARD& card)
{
	card->SetSquad(this);
	m_map_Card.insert(MAP_CARD::value_type(card->GetIndex(), card));
	m_map_AliveCard.insert(MAP_CARD::value_type(card->GetIndex(), card));
}

bool Squad::isExist(const WEAK_CARD& card)
{
	return m_map_Card.find(card->GetIndex()) != m_map_Card.end();
}

void Squad::Die(WEAK_CARD card)
{
	m_map_AliveCard.erase(card->GetIndex());
}

bool Squad::isAllDie()
{
	return m_map_AliveCard.empty();
}

WEAK_CARD Squad::Rand_Alive(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CARD Squad::High(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CARD Squad::Low(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CARD Squad::MoreThan(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CARD Squad::LessThan(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}


WEAK_CARD Squad::Similar(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CARD Squad::Same(INT variable, INT variable_detail)
{
	MAP_CARD::iterator it = m_map_AliveCard.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCard.size(); ++i)
	{
		++it;
	}
	return it->second;
}

} // namespace SH