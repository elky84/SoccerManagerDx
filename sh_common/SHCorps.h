#pragma once

#include "SHTypeDefinition.h"
#include <vector>

namespace SH
{

class Corps
{
public:
	typedef std::vector<WEAK_CARD> VECTOR_CARD;

public:
	Corps();
	~Corps();

	void AddCard(const WEAK_CARD& card);

	bool isExist(const WEAK_CARD& card);

	VECTOR_CARD& VectorCard()
	{
		return m_vectorCard;
	}

private:
	UNIQUE_SQUAD m_Squad;

	std::vector<WEAK_CARD> m_vectorCard;
};

} // namespace SH