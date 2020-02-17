#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pStartLabel->draw();
	m_pStartButton->draw();
	/*m_pPlayerCreditLabel->draw();
	m_pPlayerCreditAmount->draw();
	m_pUpButton->draw();
	m_pDownButton->draw();
	m_pSysMsg->draw();*/
	
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	/*m_pUpButton->setMousePosition(m_mousePosition);
	m_pUpButton->ButtonClick();
	m_pDownButton->setMousePosition(m_mousePosition);
	m_pDownButton->ButtonClick();*/

	/*if (m_pUpButton->ButtonClick()) {
		incCredit();
	}

	if (m_pDownButton->ButtonClick() && getCredit() != 0) {
		decCredit();
	}

	if (m_pStartButton->ButtonClick() && getCredit() == 0) {
		m_pSysMsg = new Label("You can't proceed with zero credits", "Consolas", 20, red,
			glm::vec2(Config::SCREEN_WIDTH * 0.50f, Config::SCREEN_HEIGHT * 0.70f));
	}
	else if (m_pStartButton->ButtonClick() && getCredit() > 0) {
		TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
	}

	if (getCredit() > 0) {
		m_pSysMsg = new Label(" ", "Consolas", 20, red,
			glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.75f));
	}

	m_pPlayerCreditAmount = new Label(std::to_string(getCredit()), "Consolas", 40, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.65f, Config::SCREEN_HEIGHT * 0.45f));*/
}

void StartScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;





			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	m_pStartLabel = new Label("Forgettable Slot Machine", "Consolas", 40, blue, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	/*m_pPlayerCreditLabel = new Label("Credit: ", "Consolas", 40, black,
		glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.45f));
	m_pPlayerCreditLabel->setParent(this);
	addChild(m_pPlayerCreditLabel);

	m_pSysMsg = new Label(" ", "Consolas", 20, red,
		glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.75f));
	m_pSysMsg->setParent(this);
	addChild(m_pSysMsg);

	m_pPlayerCreditAmount = new Label(std::to_string(getCredit()), "Consolas", 40, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.65f, Config::SCREEN_HEIGHT * 0.45f));
	m_pPlayerCreditLabel->setParent(this);
	addChild(m_pPlayerCreditLabel);*/

	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pStartButton);

	//m_pUpButton = new UpButton(); // instantiates up buttom
	//m_pUpButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.65f, Config::SCREEN_HEIGHT * 0.35f));
	//addChild(m_pUpButton);

	//m_pDownButton = new DownButton(); // instantiates down buttom
	//m_pDownButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.65f, Config::SCREEN_HEIGHT * 0.55f));
	//addChild(m_pDownButton);
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
