#include "stdafx.h"
#include "GameMode.h"

#include "SHMap.h"
#include "SHCard.h"
#include "SHPlayer.h"
#include "SHSquad.h"
#include "SHBall.h"

#include "GameManager.h"

#pragma comment(lib, "winmm.lib")

namespace SH
{

static const int IMAGE_UNIT = 80;
static const int TEXT_UNIT = 20;
static const int FONT_SIZE = 10;

static const int RED_Y = TEXT_UNIT;
static const int BLUE_Y = WINDOW_HEIGHT - IMAGE_UNIT;


static const int GAME_UI_TOP = TEXT_UNIT + IMAGE_UNIT;
static const int GAME_UI_BOTTOM = WINDOW_HEIGHT - TEXT_UNIT - IMAGE_UNIT;

static const int GAME_UI_LEFT = 50;
static const int GAME_UI_RIGHT = GAME_UI_LEFT + MAX_SQUAD_CARD * (IMAGE_UNIT + 5) - 5;


static const int UI_ICON_SIZE = 16;

light::POSITION_INT ConvertDrawingPosition(const light::POSITION_FLOAT& pos)
{
	float fGameUIWidth = GAME_UI_RIGHT - GAME_UI_LEFT;
	float fGameUIHeight = GAME_UI_BOTTOM - GAME_UI_TOP;
	float fWidthRatio = fGameUIWidth / SH::Map::WIDTH;
	float fHeightRatio = fGameUIHeight / SH::Map::HEIGHT;

	light::POSITION_INT rect;
	rect.X(GAME_UI_LEFT + (long)(pos.X() * fWidthRatio));
	rect.Y(GAME_UI_TOP + (long)(pos.Y() * fHeightRatio));
	return rect;
}


GameMode::GameMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(1, directX)
{
	m_TeamSprite[TEAM::RED].Load(m_direct_x, _T(".\\Map\\Template.spr"), _T("Red.png"));
	m_TeamSprite[TEAM::BLUE].Load(m_direct_x, _T(".\\Map\\Template.spr"), _T("Blue.png"));
	m_BallSprite.Load(m_direct_x, _T(".\\Map\\Ball.spr"), _T("Ball.png"));
}

GameMode::~GameMode()
{

}

bool GameMode::SetButton(WEAK_CARD card, const light::POSITION_INT& position, int n)
{
	if( false == m_vectorGuiButton[n].Create(m_direct_x, std::wstring(_T(".\\Image\\Template.spr")), card->GetCharacter()->Image(), NULL, position) )
	{
		return false;
	}

	m_vectorGuiButton[n].Set();
	return true;
}

void GameMode::Begin()
{
	m_Game = SH::GameManager::Instance()->GetGame();
	WEAK_PLAYER RedPlayer = SH::GameManager::Instance()->GetPlayer(TEAM::RED);
	WEAK_PLAYER BluePlayer = SH::GameManager::Instance()->GetPlayer(TEAM::BLUE);

	m_vectorGuiButton.resize(MAX_SQUAD_CARD * TEAM::MAX);

	Squad::MAP_CARD mapRedPlayerCard = RedPlayer->GetSquad()->MapCard();
	Squad::MAP_CARD mapBluePlayerCard = BluePlayer->GetSquad()->MapCard();

	Squad::MAP_CARD::iterator red_it = mapRedPlayerCard.begin();
	Squad::MAP_CARD::iterator blue_it = mapBluePlayerCard.begin();

	int X = GAME_UI_LEFT;
	for(int n = 0; n < MAX_SQUAD_CARD; ++n)
	{
		SetButton(red_it->second, light::POSITION_INT(X, RED_Y), n);
		SetButton(blue_it->second, light::POSITION_INT(X, BLUE_Y), n + MAX_SQUAD_CARD);

		X += (IMAGE_UNIT + 5);

		++red_it;
		++blue_it;
	}

	m_Animation.Load(m_direct_x, _T(".\\Map\\Back.ani"));
	m_Animation.Position(light::POSITION_INT(GAME_UI_LEFT, GAME_UI_TOP));
}

void GameMode::End()
{
}

void GameMode::Render()
{
	m_Animation.DrawLoop();
}

void GameMode::RenderPlayer(TEAM::type teamtype, WEAK_PLAYER Player, light::view::Sprite2D& Sprite)
{
	int n = teamtype == TEAM::RED ? 0 : MAX_SQUAD_CARD;
	Squad::MAP_CARD& mapCard = Player->GetSquad()->MapCard();
	for each(Squad::MAP_CARD::value_type val in mapCard)
	{
		WEAK_CARD card = val.second;

		light::POSITION_INT GuiPosition = m_vectorGuiButton[n++].GetPosition() + light::POSITION_INT(0, -TEXT_UNIT);

		DWORD color = D3DCOLOR_RGBA(0, 0, 0, 255);

		std::wstringstream strstream;
		strstream << card->GetCharacter()->Name();
		DrawString(strstream.str(), GuiPosition, FONT_SIZE, color);

		light::POSITION_INT convPos = ConvertDrawingPosition(card->GetPosition());
		Sprite.DrawSprite(0, convPos, 0);
		DrawString(card->GetCharacter()->Name(), convPos + light::POSITION_INT(-UI_ICON_SIZE / 2, UI_ICON_SIZE), light::RECT_INT(0, 0, UI_ICON_SIZE * 2, FONT_SIZE), FONT_SIZE, color);
	}
}

void GameMode::RenderPostUI()
{
	RenderPlayer(TEAM::RED, SH::GameManager::Instance()->GetPlayer(TEAM::RED), m_TeamSprite[TEAM::RED]);
	RenderPlayer(TEAM::BLUE, SH::GameManager::Instance()->GetPlayer(TEAM::BLUE), m_TeamSprite[TEAM::BLUE]);

	WEAK_BALL ball = m_Game->GetBall();
	light::POSITION_INT convPos = ConvertDrawingPosition(ball->GetPosition());
	m_BallSprite.DrawSprite(0, convPos, 0);
}

void GameMode::Logic()
{
	m_Game->get_turn();
}

} // namespace SH