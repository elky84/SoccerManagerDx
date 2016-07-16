#pragma once

#include "SHTypeDefinition.h"

#include <map>

namespace SH
{

static const light::POSITION_FLOAT RedPosition[MAX_SQUAD_CARD] = {
	light::POSITION_FLOAT(0, 128), 
	light::POSITION_FLOAT(0, 256), 
	light::POSITION_FLOAT(0, 384), 
	light::POSITION_FLOAT(128, 128), 
	light::POSITION_FLOAT(128, 256), 
	light::POSITION_FLOAT(128, 384),
	light::POSITION_FLOAT(256, 128),
	light::POSITION_FLOAT(256, 256),
	light::POSITION_FLOAT(256, 384),
	light::POSITION_FLOAT(256, 512),
	light::POSITION_FLOAT(128, 512),
};

static const light::POSITION_FLOAT BluePosition[MAX_SQUAD_CARD] = {
	light::POSITION_FLOAT(1792, 128), 
	light::POSITION_FLOAT(1792, 256), 
	light::POSITION_FLOAT(1792, 384), 
	light::POSITION_FLOAT(1664, 128), 
	light::POSITION_FLOAT(1664, 256), 
	light::POSITION_FLOAT(1664, 384),
	light::POSITION_FLOAT(1536, 128),
	light::POSITION_FLOAT(1536, 256),
	light::POSITION_FLOAT(1536, 384),
	light::POSITION_FLOAT(1536, 512),
	light::POSITION_FLOAT(1664, 512),
};

class Squad
{
public:
	typedef std::map<CARD_INDEX, WEAK_CARD> MAP_CARD;

public:
	Squad();
	~Squad();

	void AddCard(const WEAK_CARD& card);

	bool isExist(const WEAK_CARD& card);

	bool isAllDie();

	void Die(WEAK_CARD card);

	MAP_CARD& MapCard()
	{
		return m_map_Card;
	}

	MAP_CARD& MapAliveCard()
	{
		return m_map_AliveCard;
	}

public:
	WEAK_CARD Rand_Alive(INT variable, INT variable_detail);

	WEAK_CARD High(INT variable, INT variable_detail);
	WEAK_CARD Low(INT variable, INT variable_detail);
	WEAK_CARD MoreThan(INT variable, INT variable_detail);
	WEAK_CARD LessThan(INT variable, INT variable_detail);
	WEAK_CARD Similar(INT variable, INT variable_detail);
	WEAK_CARD Same(INT variable, INT variable_detail);

private:
	MAP_CARD m_map_Card;

	MAP_CARD m_map_AliveCard;
};

} // namespace SH