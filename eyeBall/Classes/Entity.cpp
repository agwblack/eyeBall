#include "Entity.h"

Entity::Entity(const char * imgFile, int xPos, int yPos, CCLayer* pLayer)
  : mXPosition(xPos),
    mYPosition(yPos),
    mLayer(pLayer),
    mScaleFactor(1)
{
  mSprite = CCSprite::spriteWithFile(imgFile);
  mSprite->setPosition(ccp(mXPosition, mYPosition));
  mLayer->addChild(mSprite, 0);
}

Entity::~Entity()
{
}

void Entity::setXPosition(int xPos)
{
  mXPosition = xPos;
}

void Entity::setYPosition(int yPos)
{
  mYPosition = yPos;
}

void Entity::setPosition(int xPos, int yPos)
{
  setXPosition(xPos);
  setYPosition(yPos);
}

int Entity::getXPosition()
{
  return mXPosition;
}

int Entity::getYPosition()
{
  return mYPosition;
}

CCPoint Entity::getCCPosition()
{
  return ccp(mXPosition, mYPosition);
}

CCSprite * Entity::getSprite()
{
  return mSprite;
}

void Entity::zoom(float scaleFactor)
{
  mScaleFactor = scaleFactor;
  mSprite->setScale(mScaleFactor);
}


