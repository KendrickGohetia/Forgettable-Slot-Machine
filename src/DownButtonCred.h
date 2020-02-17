#pragma once
#ifndef __DOWN_BUTTON_CRED__
#define __DOWN_BUTTON_CRED__

#include "Button.h"

class DownButtonCred : public Button
{
public:
	DownButtonCred();
	~DownButtonCred();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* defined (__DOWN_BUTTON_CRED__) */