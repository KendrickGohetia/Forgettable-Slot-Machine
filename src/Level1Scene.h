#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "SMFrame.h"
#include "BetButton.h"
#include "SpinButton.h"
#include "UpButton.h"
#include "UpButtonCred.h"
#include "DownButton.h"
#include "DownButtonCred.h"
#include "Label.h"
#include "Cherry.h"
#include "Melon.h"
#include "Lemon.h"


class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	SMFrame* m_pSMFrame;
	BetButton* m_pBetButton;
	SpinButton* m_pSpinButton;
	UpButton* m_pUpButton;
	UpButtonCred* m_pUpButtonCred;
	DownButton* m_pDownButton;
	DownButtonCred* m_pDownButtonCred;
	Cherry* m_pCherry;
	Cherry* m_pCherry1;
	Cherry* m_pCherry2;
	Cherry* m_pCherry3;
	Melon* m_pMelon;
	Melon* m_pMelon1;
	Melon* m_pMelon2;
	Melon* m_pMelon3;
	Lemon* m_pLemon;
	Lemon* m_pLemon1;
	Lemon* m_pLemon2;
	Lemon* m_pLemon3;
	Label* m_pBetLabel;
	Label* m_pBetAmountLabel;
	Label* m_pCredLabel;
	Label* m_pCredAmountLabel;
	Label* m_pSystemMsg;


	// private data member
	glm::vec2 m_mousePosition;
	

	SDL_Color blue = { 0, 0, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };
	SDL_Color green = { 0, 255, 0, 255 };
	SDL_Color black = { 255, 255, 255, 255 };

	int pBet, pCredit, r1, r2, r3;
};

#endif /* defined (__LEVEL_1_SCENE__) */
