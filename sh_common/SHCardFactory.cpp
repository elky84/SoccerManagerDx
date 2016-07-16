#include "stdafx.h"
#include "SHCardFactory.h"
#include "MetaData.h"

#include "SHCard.h"

namespace SH
{

CARD_INDEX CardFactory::m_Index = 0;

Card* CardFactory::Pick()
{
	Card* card = new Card(m_Index++);

	auto& mapCharacter = light::excel::Loader::Instance()->find<ExcelData::CharacterData>()->Map();
	card->SetCharacter(mapCharacter[rand() % mapCharacter.size() + 1]);

	return card;
}

} // namespace SH