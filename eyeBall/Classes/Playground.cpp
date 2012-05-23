#include "Playground.h"

USING_NS_CC;

CCScene* Playground::scene()
{
	CCScene *scene = CCScene::node();
	
	Playground *layer = Playground::node();

	scene->addChild(layer);

	return scene;
}

bool Playground::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// add background
  m_background = new Entity("HelloWorld.png", size.width/2,
      size.height/2, this);
	// add eyeball
  m_eyeBall = new Entity("eyeBall.png", size.width/2. size.height/2, this);

  this->scheduleUpdate();
	return true;
}

void Playground::update(ccTime dt)
{
  // update eyeball state (velocity, acceleration, etc.)
  m_eyeBall->update(dt);

  // Move the background according to the eyeBall's current magnitude and
  // direction of motion
  // Use d = st
  // Recall that Velocities are signed values in our model. Negative indicates
  // leftward and upward movement.
  // We multiply by (-1) because background movement happens in the opposite
  // direction to eyeBall movement
  float xDisplacement = (-1) * dt * m_eyeBall->getXVelocity();
  float yDisplacement = (-1) * dt * m_eyeBall->getYVelocity();

  // When there are more entities, we must do this for all of them.
  m_background->setPosition(m_background->getXPosition() + xDisplacement, 
                            m_background->getYPosition() + yDisplacement); 
}
