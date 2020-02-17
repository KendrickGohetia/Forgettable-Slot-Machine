#pragma once
#ifndef __CHERRY__
#define __CHERRY__

#include "Button.h"

class Cherry : public Button
{
public:
	Cherry();
	~Cherry();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* defined (__CHERRY__) */