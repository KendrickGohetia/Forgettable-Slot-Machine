#pragma once
#ifndef __DOWN_BUTTON__
#define __DOWN_BUTTON__

#include "Button.h"

class DownButton : public Button
{
public:
	DownButton();
	~DownButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__DOWN_BUTTON__) */