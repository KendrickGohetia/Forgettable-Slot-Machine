#include "DownButton.h"
#include "Game.h"

DownButton::DownButton()
// call super constructor
	:Button(
		"../Assets/textures/downArrowBlue.png",
		"downArrowBlue",
		SPIN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

DownButton::~DownButton()
{
}

bool DownButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			decBet();
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


