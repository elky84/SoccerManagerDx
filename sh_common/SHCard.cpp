#include "stdafx.h"
#include "SHCard.h"

#include "MetaData.h"

#include "SHDecide.h"
#include "SHSquad.h"

namespace SH
{

Card::Card(const CARD_INDEX index)
	: m_Index(index)
	, m_DecideTime(0)
	, m_ActionCoolTime(0)
    , m_Character(new ExcelData::Character)
{
}

Card::~Card()
{
}

bool Card::DecideTiming()
{
	if( 0 < m_DecideTime - GetCharacter()->Decide_Cooltime() )
	{
		return false;
	}

	m_DecideTime = 0;
	return true;
}

bool Card::ActionTiming()
{
	if( 0 < m_ActionCoolTime - GetCharacter()->Action_Cooltime() )
	{
		return false;
	}

	m_ActionCoolTime = 0;
	return true;
}

void Card::AccumTime()
{
	m_DecideTime += TURN_UNIT; 
	m_ActionCoolTime += TURN_UNIT;
}

void Card::SetCharacter(ExcelData::Character& _character)
{
	*m_Character = _character;
	m_DecideTime = _character.Decide_Cooltime();
}

} // namespace SH