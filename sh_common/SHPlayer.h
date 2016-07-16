#pragma once

#include "SHTypeDefinition.h"
#include <vector>

namespace SH
{

class Player
{
public:
	typedef std::vector<SHARED_CARD> VECTOR_CARD;

public:
	Player();
	~Player();

	void AddCard(Card* card);

	bool isExist(const WEAK_CARD& card);

	WEAK_CARD PickCard();

	void PickCorps();

	void PickSquad(TEAM::type team);

	WEAK_SQUAD GetSquad()
	{
		return m_Squad;
	}

	WEAK_CORPS GetCorps()
	{
		return m_Corps;
	}

	VECTOR_CARD& VectorCard()
	{
		return m_vectorCard;
	}

public:

	void Name(const std::wstring& str)
	{
		m_Name = str;
	}

	const std::wstring& Name() const
	{
		return m_Name;
	}

private:
	std::wstring m_Name;

	UNIQUE_SQUAD m_Squad;

	UNIQUE_CORPS m_Corps;

	VECTOR_CARD m_vectorCard;
};

} // namespace SH