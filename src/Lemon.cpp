#include "Lemon.h"
#include "Game.h"

Lemon::Lemon()
// call super constructor
	:Button(
		"../Assets/textures/lemon.png",
		"lemon",
		LEMON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

Lemon::~Lemon()
{
}

bool Lemon::ButtonClick()
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


