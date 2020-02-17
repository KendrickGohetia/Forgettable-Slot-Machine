#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//m_pIsland->draw();
	
	m_pSMFrame->draw();
	m_pBetButton->draw();
	m_pSpinButton->draw();
	m_pUpButton->draw();
	m_pUpButtonCred->draw();
	m_pDownButton->draw();
	m_pDownButtonCred->draw();
	m_pBetLabel->draw();
	m_pCredLabel->draw();
	m_pBetAmountLabel->draw();
	m_pCredAmountLabel->draw();
	m_pSystemMsg->draw();

	if (r1 == 0) {
		m_pCherry->draw();
		m_pMelon->draw();
		m_pLemon->draw();
	}

	switch (r1) {
	case 1:
		m_pCherry1->draw();
		break;
	case 2:
		m_pMelon1->draw();
		break;
	case 3:
		m_pLemon1->draw();
		break;
	}

	switch (r2) {
	case 1:
		m_pCherry2->draw();
		break;
	case 2:
		m_pMelon2->draw();
		break;
	case 3:
		m_pLemon2->draw();
		break;
	}

	switch (r3) {
	case 1:
		m_pCherry3->draw();
		break;
	case 2:
		m_pMelon3->draw();
		break;
	case 3:
		m_pLemon3->draw();
		break;
	}


}

void Level1Scene::update()
{
	m_pBetButton->setMousePosition(m_mousePosition);
	m_pBetButton->ButtonClick();
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pSpinButton->ButtonClick();
	m_pUpButton->setMousePosition(m_mousePosition);
	m_pUpButton->ButtonClick();
	m_pUpButtonCred->setMousePosition(m_mousePosition);
	m_pUpButtonCred->ButtonClick();
	m_pDownButton->setMousePosition(m_mousePosition);
	m_pDownButton->ButtonClick();
	m_pDownButtonCred->setMousePosition(m_mousePosition);
	m_pDownButtonCred->ButtonClick();

	pBet = m_pUpButton->getBet() - m_pDownButton->getBet();

	if (pBet < 0) {
		pBet = 0;
	}

	pCredit = m_pUpButtonCred->getCredit() - m_pDownButtonCred->getCredit();

	if (pCredit < 0) {
		pCredit = 0;
	}

	//if (m_pUpButton->ButtonClick()) {
	//	incBet();
	//	//std::cout << "Bet: " << getBet() << std::endl;
	//}

	//if (m_pDownButton->ButtonClick() && getBet() != 0) {
	//	decBet();
	//	//std::cout << "Bet: " << getBet() << std::endl;
	//

	if (pBet > pCredit) {
		m_pSystemMsg = new Label("You cannot bet more than your credit value!", "Consolas", 15, red,
			glm::vec2(Config::SCREEN_WIDTH * 0.53f, Config::SCREEN_HEIGHT * 0.60f));

		m_pBetAmountLabel = new Label(std::to_string(pBet), "Consolas", 25, red,
			glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.87));
	}
	else if (pBet <= pCredit) {
		m_pSystemMsg = new Label(" ", "Consolas", 20, red,
			glm::vec2(Config::SCREEN_WIDTH * 0.53f, Config::SCREEN_HEIGHT * 0.80f));

		m_pBetAmountLabel = new Label(std::to_string(pBet), "Consolas", 25, blue,
			glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.87));
	}

	m_pCredAmountLabel = new Label(std::to_string(pCredit), "Consolas", 25, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.13f));

	if (m_pSpinButton->ButtonClick()) {

		switch (r1) {
		case 1:
			delete m_pCherry1;
			break;
		case 2:
			delete m_pMelon1;
			break;
		case 3:
			delete m_pLemon1;
			break;
		}

		switch (r2) {
		case 1:
			delete m_pCherry2;
			break;
		case 2:
			delete m_pMelon2;
			break;
		case 3:
			delete m_pLemon2;
			break;
		}

		switch (r3) {
		case 1:
			delete m_pCherry3;
			break;
		case 2:
			delete m_pMelon3;
			break;
		case 3:
			delete m_pLemon3;
			break;
		}

		if (r1 == 0) {
			delete m_pCherry;
			delete m_pMelon;
			delete m_pLemon;
		}

		r1 = m_pSpinButton->getR1();
		r2 = m_pSpinButton->getR2();
		r3 = m_pSpinButton->getR3();

		
		switch (r1) {
		case 1:
			m_pCherry1 = new Cherry();
			m_pCherry1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.39f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pCherry1);
			m_pCherry1->draw();
			break;
		case 2:
			m_pMelon1 = new Melon();
			m_pMelon1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.39f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pMelon1);
			m_pMelon1->draw();
			break;
		case 3:
			m_pLemon1 = new Lemon();
			m_pLemon1->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.39f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pLemon1);
			m_pLemon1->draw();
			break;
		}

		switch (r2) {
		case 1:
			m_pCherry2 = new Cherry();
			m_pCherry2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.50f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pCherry2);
			m_pCherry2->draw();
			break;
		case 2:
			m_pMelon2 = new Melon();
			m_pMelon2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.50f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pMelon2);
			m_pMelon2->draw();
			break;
		case 3: 
			m_pLemon2 = new Lemon();
			m_pLemon2->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.50f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pLemon2);
			m_pLemon2->draw();
			break;
		}
		
		switch (r3) {
		case 1:
			m_pCherry3 = new Cherry();
			m_pCherry3->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.62f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pCherry3);
			m_pCherry3->draw();
			break;
		case 2:
			m_pMelon3 = new Melon();
			m_pMelon3->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.62f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pMelon3);
			m_pMelon3->draw();
			break;
		case 3:
			m_pLemon3 = new Lemon();
			m_pLemon3->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.62f, Config::SCREEN_HEIGHT * 0.43f));
			addChild(m_pLemon3);
			m_pLemon3->draw();
			break;
		}
	}
	
	//m_pBetLabel->update();
	//m_pPlane->setVelocity(m_pPlane->getVelocity() * 0.97f);
	// plane moving with mouse motion
	//m_pPlane->setPosition(glm::vec2(m_mousePosition.x, m_pPlane->getPosition().y));

	//CollisionManager::AABBCheck(m_pPlane, m_pIsland);

	//CollisionManager::squaredRadiusCheck(m_SMFrame, m_pIsland);

}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
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
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pUpButton->setMouseButtonClicked(true);
				m_pUpButtonCred->setMouseButtonClicked(true);
				m_pDownButton->setMouseButtonClicked(true);
				m_pDownButtonCred->setMouseButtonClicked(true);
				m_pSpinButton->setMouseButtonClicked(true);
				m_pBetButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pUpButton->setMouseButtonClicked(false);
				m_pUpButtonCred->setMouseButtonClicked(false);
				m_pDownButton->setMouseButtonClicked(false);
				m_pDownButtonCred->setMouseButtonClicked(false);
				m_pSpinButton->setMouseButtonClicked(false);
				m_pBetButton->setMouseButtonClicked(false);
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
				//TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				//m_pPlane->move(LEFT);
				break;
			case SDLK_d:
				//m_pPlane->move(RIGHT);
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				//m_pPlane->setIsMoving(false);
				break;
			case SDLK_d:
				//m_pPlane->setIsMoving(false);
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pSMFrame = new SMFrame(); // instantiates Frame
	addChild(m_pSMFrame);

	m_pBetButton = new BetButton(); // instantiates bet buttom
	m_pBetButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.475f, Config::SCREEN_HEIGHT * 0.53f));
	addChild(m_pBetButton);

	m_pSpinButton = new SpinButton(); // instantiates spin buttom
	m_pSpinButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.53f, Config::SCREEN_HEIGHT * 0.53f));
	addChild(m_pBetButton);

	m_pUpButton = new UpButton(); // instantiates up buttom
	m_pUpButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.80));
	addChild(m_pUpButton);

	m_pUpButtonCred = new UpButtonCred(); // instantiates up cred buttom
	m_pUpButtonCred->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.05f));
	addChild(m_pUpButtonCred);

	m_pDownButtonCred = new DownButtonCred(); // instantiates down cred buttom
	m_pDownButtonCred->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.20f));
	addChild(m_pDownButtonCred);

	m_pDownButton = new DownButton(); // instantiates down buttom
	m_pDownButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.95f));
	addChild(m_pDownButton);

	m_pCherry = new Cherry(); // instantiates Cherry
	m_pCherry->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.39f, Config::SCREEN_HEIGHT * 0.43f));
	addChild(m_pCherry);
	m_pCherry->draw();

	m_pMelon = new Melon(); // instantiates Melon
	m_pMelon->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.50f, Config::SCREEN_HEIGHT * 0.43f));
	addChild(m_pMelon);

	m_pLemon = new Lemon(); // instantiates Lemon
	m_pLemon->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.62f, Config::SCREEN_HEIGHT * 0.43f));
	addChild(m_pLemon);

	m_pBetLabel = new Label("Bet:", "Consolas", 25, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.10f, Config::SCREEN_HEIGHT * 0.87f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);

	m_pCredLabel = new Label("Credit:", "Consolas", 25, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.1f, Config::SCREEN_HEIGHT * 0.13f));
	m_pCredLabel->setParent(this);
	addChild(m_pCredLabel);

	m_pBetAmountLabel = new Label(std::to_string(pBet), "Consolas", 25, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.87f));
	m_pBetAmountLabel->setParent(this);
	addChild(m_pBetAmountLabel);

	m_pCredAmountLabel = new Label(std::to_string(pCredit), "Consolas", 25, blue,
		glm::vec2(Config::SCREEN_WIDTH * 0.30f, Config::SCREEN_HEIGHT * 0.13f));
	m_pBetAmountLabel->setParent(this);
	addChild(m_pBetAmountLabel);

	m_pSystemMsg = new Label(" ", "Consolas", 15, red,
		glm::vec2(Config::SCREEN_WIDTH * 0.53f, Config::SCREEN_HEIGHT * 0.80f));
	m_pSystemMsg->setParent(this);
	addChild(m_pSystemMsg);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}
