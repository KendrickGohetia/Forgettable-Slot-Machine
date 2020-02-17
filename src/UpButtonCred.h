#pragma once
#ifndef __UP_BUTTON_CRED__
#define __UP_BUTTON_CRED__

#include "Button.h"

class UpButtonCred : public Button
{
public:
	UpButtonCred();
	~UpButtonCred();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* defined (__UP_BUTTON_CRED__) */