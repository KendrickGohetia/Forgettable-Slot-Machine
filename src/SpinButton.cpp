#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
// call super constructor
	:Button(
		"../Assets/textures/spin.png",
		"spin",
		SPIN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			randNums();
			std::cout << "R1: " << getR1() << std::endl;
			std::cout << "R2: " << getR2() << std::endl;
			std::cout << "R3: " << getR3() << std::endl;

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


