#include "Cherry.h"
#include "Game.h"

Cherry::Cherry()
// call super constructor
	:Button(
		"../Assets/textures/cherries.png",
		"cherry",
		CHERRY, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

Cherry::~Cherry()
{
}

bool Cherry::ButtonClick()
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

