#include "Melon.h"
#include "Game.h"

Melon::Melon()
// call super constructor
	:Button(
		"../Assets/textures/melon.png",
		"melon",
		MELON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

Melon::~Melon()
{
}

bool Melon::ButtonClick()
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


