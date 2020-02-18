#include "DownButtonCred.h"
#include "Game.h"

DownButtonCred::DownButtonCred()
// call super constructor
	:Button(
		"../Assets/textures/downArrowBlue.png",
		"downArrowBlue",
		DOWN_BUTTON_CRED, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

DownButtonCred::~DownButtonCred()
{
}

bool DownButtonCred::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			decCredit();
			//std::cout << "Credit: " << getCredit() << std::endl;
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


