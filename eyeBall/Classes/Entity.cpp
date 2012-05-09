#include "Entity.h"

/* Temp constants for use in example code in update method */
#define MAX_SCALE_FACTOR 2
#define MIN_SCALE_FACTOR 0.5
#define ZOOM_RATE 1 // go from 1 to 2 in 1 second

Entity::Entity(const char * imgFile, int xPos, int yPos, CCLayer* pLayer)
  : mXPosition(xPos),
    mYPosition(yPos),
    mLayer(pLayer),
    mEnlarging(true),
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

void Entity::update(CCTime dt)
{
  /* This function currently just contains some example code which causes the
   * sprite to continuously get larger and smaller over time */
  if (mEnlarging)
  {
    zoom(mScaleFactor + dt * ZOOM_RATE);
    if (mScaleFactor >= MAX_SCALE_FACTOR)
      mEnlarging = false;
  }
  else
  {
    zoom(mScaleFactor - dt * ZOOM_RATE);
    if (mScaleFactor <= MIN_SCALE_FACTOR)
      mEnlarging = true;
  }
}
