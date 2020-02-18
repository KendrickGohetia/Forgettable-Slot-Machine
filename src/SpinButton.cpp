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

			r1 = getR1();
			r2 = getR2();
			r3 = getR3();

			if (r1 == r2 || r1 == r3 || r2 == r1 || r2 == r3 || r3 == r1 || r3 == r2) {
				wonCreds(2);
			}
			else if ((r1 == r2 && r1 == r3) || (r2 == r1 && r2 == r3) || (r3 == r1 && r3 == r2)) {
				wonCreds(3);
			}

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


