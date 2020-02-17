#pragma once
#ifndef __LEMON__
#define __LEMON__

#include "Button.h"

class Lemon : public Button
{
public:
	Lemon();
	~Lemon();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* defined (__LEMON__) */#pragma once
