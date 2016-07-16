#include "stdafx.h"
#include "SettingMode.h"
#include "WindowUtil.h"

#include "SHCard.h"
#include "SHCardFactory.h"
#include "SHGame.h"
#include "SHPlayer.h"
#include "SHMap.h"

#include "SHSquad.h"
#include "GameManager.h"

namespace SH
{

SettingMode::SettingMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(0, directX)
{

}

SettingMode::~SettingMode()
{

}

static const TCHAR* NAME[SH::Game::MAX_TEAM] = {_T("BLUE"), _T("RED")};

void SettingMode::Begin()
{
	WEAK_GAME Game = SH::GameManager::Instance()->GetGame();
	for(int n = 0; n < SH::Game::MAX_TEAM; ++n)
	{
		SH::SHARED_PLAYER Player(new SH::Player);
		Player->Name(NAME[n]);

		while(Player->VectorCard().size() != MAX_DECK)
		{
			SH::Card* Card = SH::CardFactory::Pick();
			if( false == Player->isExist(Card) )
			{
				Player->AddCard(Card);
			}
		}

		Player->PickCorps();
		Player->PickSquad((TEAM::type)n);

		Game->Add(Player->GetCorps());
		Game->Add(Player->GetSquad());
		SH::GameManager::Instance()->AddPlayer(Player);
	}
}

void SettingMode::End()
{
}

void SettingMode::Render()
{
	
}

void SettingMode::RenderPostUI()
{
}

void SettingMode::Logic()
{
	ChangeMode(1);
}

} // namespace SH
