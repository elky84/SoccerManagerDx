#include "stdafx.h"
#include "SHDecide.h"

#include "SHCard.h"
#include "SHGame.h"
#include "SHSquad.h"
#include "SHAction.h"

namespace SH
{

Decide::Decide()
{

}

Decide::~Decide()
{

}

bool Decide::Select(WEAK_CARD card)
{
	auto& mapDecide = light::excel::Loader::Instance()->find<ExcelData::DecideInfoData>()->Map();
	auto it = mapDecide.find(card->GetCharacter()->Decide());
	if(it == mapDecide.end())
		return false;

	card->SetDecideInfo(it->second);
	return true;
}

WEAK_CARD Decide::SelectTarget(WEAK_CARD card)
{
	VECTOR_SQUAD& vectorSquad = m_Game->VectorSquad();
	WEAK_SQUAD rival = vectorSquad[TEAM::RED]->isExist(card) == false ? vectorSquad[TEAM::RED] : vectorSquad[TEAM::BLUE];
	if(rival->isAllDie())
		return NULL;

	ExcelData::DecideInfo& decideinfo = card->GetDecideInfo();
	switch(decideinfo.Targeting())
	{
	case DecideTargeting::HIGH:
		return rival->High(decideinfo.Standard(), decideinfo.Standard_Detail());
	case DecideTargeting::LOW:
		return rival->Low(decideinfo.Standard(), decideinfo.Standard_Detail());
	case DecideTargeting::MORE_THAN:
		return rival->MoreThan(decideinfo.Standard(), decideinfo.Standard_Detail());
	case DecideTargeting::LESS_THAN:
		return rival->LessThan(decideinfo.Standard(), decideinfo.Standard_Detail());
	case DecideTargeting::SIMILAR:
		return rival->Similar(decideinfo.Standard(), decideinfo.Standard_Detail());
	case DecideTargeting::SAME:
		return rival->Same(decideinfo.Standard(), decideinfo.Standard_Detail());
	default:
		return rival->Rand_Alive(decideinfo.Standard(), decideinfo.Standard_Detail());
	}
}

Action* Decide::SelectAction(WEAK_CARD card)
{
    Action* action = new Action();
	action->Set((DecideAction::Type)card->GetDecideInfo().Type(), card, SelectTarget(card));
	return action;
}

} // namespace SH