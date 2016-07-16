#include "stdafx.h"
#include "SHAction.h"

#include "SHCard.h"
#include "SHMap.h"

#include "SHGame.h"

namespace SH
{

Action::Action()
	: m_Type(DecideAction::NONE)
{

}

Action::~Action()
{

}

void Action::Set(DecideAction::Type type, WEAK_CARD card, WEAK_CARD target)
{
	m_Type = type;
	m_Card = card;
	m_Target = target;
}

bool Action::Update()
{
	return Move();
}

bool Action::Move()
{
	light::POSITION_FLOAT TargetPos = m_Card->GetPosition() - m_Target->GetPosition();
	float Sum = sqrt((TargetPos.X() * TargetPos.X()) + (TargetPos.Y() * TargetPos.Y()));
	float Radius = ((Card::HEIGHT + Card::WIDTH) / 2.0f) / 2.0f;
	if( Sum + Radius < m_Card->GetCharacter()->Sight() + Radius )
	{
		return false;
	}

	float force = Sum < m_Card->GetCharacter()->Speed() ? Sum : (float)m_Card->GetCharacter()->Speed();
	force = force / 10;
	m_Card->GetPosition().Force(force, m_Target->GetPosition());
	return true;
}

} // namespace SH