#include "UpButton.h"
#include "Game.h"

UpButton::UpButton()
// call super constructor
	:Button(
		"../Assets/textures/upArrowBlue.png",
		"upArrowBlue",
		SPIN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

UpButton::~UpButton()
{
}

bool UpButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			incBet();
			//std::cout << "Bet: " << getBet() << std::endl;
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


