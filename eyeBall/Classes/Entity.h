#ifndef ENTITY_H
#define ENTITY_H

#include "cocos2d.h"

USING_NS_CC;

/**
 * Entity base class. 
 *  
 * Every on screen element is an Entity.
 *
 * Consider using Strategy pattern for movement function, i.e. we can move
 * relative to screen, or relative to other object, or not at all. Might be a
 * better solution than have lots of descendant classes with different movement
 * functions (not least because we can then dynamically switch between movement
 * functions).
 *
 * How to handle entities whose appearance change, rather than just
 * moves/zooms/fades? i.e. those for which we need multiple image files?
 *
 * Uses CCSprite underneath.
 */
class Entity
{
  public:
    /**
     * Various constructors
     */
    Entity(const char * imgFile, const double xPos, const double yPos, CCLayer*
        pLayer);

    /**
     * Destructor
     */
    ~Entity();

    /**
     * Setter methods
     */
    void setPosition(Cartesian pos) { m_position = pos; }
    inline void setPosition(double xPos, double yPos);
    void setXPosition(double xPos) { m_position.x = xPos; }
    void setYPosition(double yPos) { m_position.y = yPos; }

    void setAcceleration(Cartesian acc) { m_acceleration = acc }
    inline void setAcceleration(double xAcc, double yAcc);
    void setXAcceleration(double xAcc) { m_acceleration.x = xAcc; }
    void setYAcceleration(double yAcc) { m_acceleration.y = yAcc; }

    void setVelocity(Cartesian vel) { m_velocity = vel }
    inline void setVelocity(double xVel, double yVel);
    void setXVelocity(double xVel) { m_velocity.x = xVel; }
    void setYVelocity(double yVel) { m_velocity.y = yVel; }

    /**
     * Getter methods
     */
    Cartesian position() { return m_position; }
    Cartesian velocity() { return m_velocity; }
    Cartesian acceleration() { return m_acceleration; }
    Cartesian propulsion() { return m_propulstion; }
    Cartesian distanceToGoal() { return m_distanceToGoal; } // Not sure about this

    double mass() { return m_mass; }
    double magnetism() { return m_magnetism; }
    //CCPoint getCCPosition();
    CCSprite* sprite() { return m_sprite; }

    /**
     * Consider: Zoom methods?
     */

    /**
     * Consider: Fade methods?
     */

    /**
     * Update method. Called every loop.
     */
    virtual void update(double dt);

    /**
     * Method to set the Physics regime.
     */
    inline void setForcesModel(Physics::calculateForces model);
    inline void setAccelerationModel(Physics::calculateAcceleration model);
    inline void setVelocity(Physics::calculateVelocity model);

    /**
     * Utility methods
     */
    void updateSpritePosition();
    void updateDistanceToGoal(); // not sure about this.
  private:
    /* All Entities have a current position on the screen */
    Cartesian m_position;
    Cartesian m_velocity;
    Cartesian m_acceleration;
    Cartesian m_propulsion;

    Cartesian m_distanceToGoal; // Not sure about this

    double m_magnetism;
    double m_mass;

    double m_scaleFactor;

    /* This is the layer that the entity is associated with. The entity is
     * responsible for adding and removing its sprite from the layer */
    CCLayer * m_layer;
    CCSprite * m_sprite;

    /* Function pointers denoting the various physics models */
    Physics::forcesModel fp_calculateForces;
    Physics::accelerationModel fp_calculateAcceleration;
    Physics::velocityModel fp_calculateVelocity;
    Physics::displacementModel fp_calculateDisplacement;
};

inline void Entity::setPosition(double xPos, double yPos)
{
  m_position.x = xPos;
  m_position.y = yPos;
}

inline void Entity::setVelocity(double xVel, double yVel)
{
  m_velocity.x = xVel;
  m_velocity.y = yVel;
}

inline void Entity::setAcceleration(double xAcc, double yAcc)
{
  m_acceleration.x = xAcc;
  m_acceleration.y = yAcc;
}

inline void Entity::setForcesModel(Physics::forcesModel model)
{
  fp_calculateForces = model;
}

inline void Entity::setAccelerationModel(Physics::accelerationModel model)
{
  fp_calculateAcceleration = model;
}

inline void Entity::setVelocityModel(Physics::velocityModel model)
{
  fp_calculateVelocity = model;
}

inline void Entity::setDisplacementModel(Physics::displacementModel model)
{
  fp_calculateDisplacement = model;
}
#endif
