#pragma once

#include "Mode.h"

namespace SH
{

class SettingMode : public light::view::Mode
{
public:
	SettingMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~SettingMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();
};

} // namespace SH