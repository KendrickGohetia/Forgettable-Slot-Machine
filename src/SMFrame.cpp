#include "SMFrame.h"
#include "Game.h"

SMFrame::SMFrame() //:m_maxSpeed(10.0f), m_isMoving(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/SMFrame_blank.png",
		"smframe", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("smframe");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 217.5f));
	setIsColliding(false);
	setType(GameObjectType::SMFRAME);

}

SMFrame::~SMFrame()
{
}

void SMFrame::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("smframe", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void SMFrame::update()
{
}

void SMFrame::clean()
{
}
