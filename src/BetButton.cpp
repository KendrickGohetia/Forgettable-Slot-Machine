#include "BetButton.h"
#include "Game.h"

BetButton::BetButton()
// call super constructor
	:Button(
		"../Assets/textures/bet.png",
		"betButton",
		BET_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

BetButton::~BetButton()
{
}

bool BetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			//Game::Instance()->changeSceneState(LEVEL1_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


