#include "Entity.h"

Entity::Entity(const char * file, const CCPoint position)
{
  pSprite = CCSprite::spriteWithFile(file);
  pSprite->setPosition(position);
}

Entity::~Entity()
{
}

void Entity::setPosition(const CCPoint position)
{
  pSprite->setPosition(position);
}

void Entity::setXPosition(int xPos)
{
  xPosition = xPos;
  pSprite->setPosition(ccp(xPosition, yPosition));
}

void Entity::setYPosition(int yPos)
{
  yPosition = yPos;
  pSprite->setPosition(ccp(xPosition, yPosition));
}


int Entity::getXPosition()
{
  return xPosition;
}

int Entity::getYPosition()
{
  return yPosition;
}

CCPoint Entity::getPosition()
{
  return ccp(xPosition, yPosition);
}

CCSprite* Entity::getSprite()
{
  return pSprite;
}
