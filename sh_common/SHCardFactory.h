#pragma once

#include "SHTypeDefinition.h"

namespace SH
{

class CardFactory
{
public:
	static Card* Pick();

public:
	static CARD_INDEX m_Index;
};

} // namespace SH