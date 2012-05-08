#ifndef ENTITY_H
#define ENTITY_H

#include "cocos2d.h"

USING_NS_CC;

/**
 * Base class that represents an on-screen entity, e.g. player, enemy, score
 * bar, background, etc.
 */


class Entity
{
  public:
    Entity(const char* imgFile, const CCPoint position);
    ~Entity();

  /* Getter and Setter methods */
  public:
    CCSprite* getSprite();
    CCPoint getPosition();
    int getXPosition();
    int getYPosition();

    void setPosition(const CCPoint position);
    void setXPosition(const int xPos);
    void setYPosition(const int yPos);

  private:
    CCSprite* pSprite;
    int xPosition;
    int yPosition;
};

#endif
