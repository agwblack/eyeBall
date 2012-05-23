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

void Entity::update(float t)
{
  // update acceleration
  // Most complex thing is working out the different forces at work.
  // These in turn depend on how we think of the circumstances of the eyeBall,
  // conceptually, e.g.:
  /*
     * Falling through the air
        - Need gravitiational field strength
        - Air resistance (dependent on velocity)
     * Rolling around on a table
        - Friction (dependent on velocity? Not sure)
        - Gravity plays a role if the table has hills in it.
     * Magnetic repulsion
        - Strength of magnet
        - Distance from magnet

     We should create calculateForces functions for as many of these as we
     like (and different implementations for each). That way we can switch
     between them readily, both for testing and for additional game features.
  */
  updateAcceleration(m_physicsRegime(this), m_mass);

  // update velocity (suvat equations: v = at + u)
  mXVelocity = updateVelocity(mXVelocity, mXAcceleration, t); 
  mYVelocity = updateVelocity(mYVelocity, mYAcceleration, t);
}

/**
 * SUVAT equation:
 * Final velocity = acceleration * time + initial velocity
 */
float Entity::updateVelocity(float u, float a, float t)
{
  return a * t + u;
}

/**
 * Newton's second law
 * Force = mass * acceleration
 */
float Entity::updateAcceleration(float f, float m)
{
  return f / m;
}

/**
 * Calculates forces as if repelled by magnet - classical
 * Force = (mu * qm1 * qm2) / (4 * pi * r-squared)
 *  where:
      - mu = permeability of intervening medium (tesla-meter per ampere)
      - qm1, qm2 = magnitudes of magnetic poles (ampere-meter)
      - r = separation (meter)
   http://en.wikipedia.org/wiki/Force_between_magnets#Force_between_two_magnetic_poles
 */
float Entity::calculateForces(float propulsion, float distanceToGoal)
{
  float permeability = 1;
  float eyeMagnetism = 1;
  float goalMagnetism = 1;

  return propulsion - (permeability * eyeMagnetism * goalMagnetism) / 
                      (4 * 3.7141 * distanceToGoal);
}
