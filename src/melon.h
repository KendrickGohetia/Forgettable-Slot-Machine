#pragma once
#ifndef __MELON__
#define __MELON__

#include "Button.h"

class Melon : public Button
{
public:
	Melon();
	~Melon();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* defined (__MELON__) */