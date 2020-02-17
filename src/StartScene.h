#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "UpButton.h"
#include "DownButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// Game Objects
	Label* m_pStartLabel;
	/*Label* m_pPlayerCreditLabel;
	Label* m_pPlayerCreditAmount;
	Label* m_pSysMsg;*/
	StartButton* m_pStartButton;
	/*UpButton* m_pUpButton;
	DownButton* m_pDownButton;*/


	// private data member
	glm::vec2 m_mousePosition;


	SDL_Color blue = { 0, 0, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };
	SDL_Color green = { 0, 255, 0, 255 };
	SDL_Color black = { 0, 0, 0, 255 };

};

#endif /* defined (__START_SCENE__) */