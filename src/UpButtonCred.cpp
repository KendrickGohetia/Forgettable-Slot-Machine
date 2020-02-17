#include "UpButtonCred.h"
#include "Game.h"

UpButtonCred::UpButtonCred()
// call super constructor
	:Button(
		"../Assets/textures/upArrowBlue.png",
		"upArrowBlue",
		UP_BUTTON_CRED, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

UpButtonCred::~UpButtonCred()
{
}

bool UpButtonCred::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			incCredit();
			std::cout << "Credit: " << getCredit() << std::endl;
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


