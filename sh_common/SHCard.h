#pragma once

#include "SHTypeDefinition.h"
#include <vector>
#include "MetaData.h"

#include "SHDecide.h"

namespace SH
{

class Card
{
public:
	static const int HEIGHT = 128;
	static const int WIDTH = 128;

public:
	Card(const CARD_INDEX index);
	~Card();

	void SetPosition(const light::POSITION_FLOAT& position)
	{
		m_Position = position;
	}

	light::POSITION_FLOAT& GetPosition()
	{
		return m_Position;
	}

	float X() const
	{
		return m_Position.X();
	}

	float Y() const
	{
		return m_Position.Y();
	}

	void SetSquad(WEAK_SQUAD squad)
	{
		m_Squad = squad;
	}

	void SetCharacter(ExcelData::Character& _character);

	ExcelData::WEAK_CHARACTER GetCharacter() const
	{
		return m_Character;
	}

	void SetDecideInfo(const ExcelData::DecideInfo& info)
	{
		m_DecideInfo = info;
	}

	ExcelData::DecideInfo GetDecideInfo() const
	{
		return m_DecideInfo;
	}

	bool DecideTiming();

	void Render();

	bool ActionTiming();

	void AccumTime();

	CARD_INDEX GetIndex() const
	{
		return m_Index;
	}

private:
	CARD_INDEX m_Index;

	light::POSITION_FLOAT m_Position;

	ExcelData::DecideInfo m_DecideInfo;

	int m_DecideTime, m_ActionCoolTime;

	UNIQUE_DECIDE m_Decide;

	ExcelData::UNIQUE_CHARACTER m_Character;

	WEAK_SQUAD m_Squad;
};

} // namespace SH