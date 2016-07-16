#pragma once

#include "Mode.h"

#include <vector>

#include "Animation2D.h"
#include "Sprite2D.h"

#include "SHGame.h"

#include "GuiButton.h"

namespace SH
{

class GameMode : public light::view::Mode
{
public:
	GameMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~GameMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	bool SetButton(WEAK_CARD card, const light::POSITION_INT& position, int n);

private:
	void RenderPlayer(TEAM::type teamtype, WEAK_PLAYER Player, light::view::Sprite2D& Sprite);

private:
	std::vector<light::view::GuiButton> m_vectorGuiButton;

	WEAK_GAME m_Game;

	light::view::Animation2D m_Animation;

	light::view::Sprite2D m_BallSprite;

	light::view::Sprite2D m_TeamSprite[Game::MAX_TEAM];
};

} // namespace SH