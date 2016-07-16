#include "stdafx.h"
#include "SHCorps.h"

#include "SHSquad.h"
#include "SHCard.h"

#include <algorithm>

namespace SH
{

Corps::Corps()
{

}

Corps::~Corps()
{

}

void Corps::AddCard(const WEAK_CARD& card)
{
	m_vectorCard.push_back(card);
}

bool Corps::isExist(const WEAK_CARD& card)
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