#pragma once

#include "SHTypeDefinition.h"

namespace SH
{

class Ball
{
public:
	Ball();
	~Ball();

	light::POSITION_FLOAT GetPosition() const
	{
		return m_Position;
	}

	void SetPosition(light::POSITION_FLOAT& position)
	{
		m_Position = position;
	}

private:
	light::POSITION_FLOAT m_Position;
};

} // namespace SH