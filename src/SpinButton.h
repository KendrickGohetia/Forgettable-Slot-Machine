#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
	int r1, r2, r3;
};

#endif /* defined (__SPIN_BUTTON__) */