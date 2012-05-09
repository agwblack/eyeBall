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
    Entity(const char * imgFile, const int xPos, const int yPos, CCLayer*
        pLayer);

    /**
     * Destructor
     */
    ~Entity();

    /**
     * Setter methods
     */
    void setXPosition(int xPos);
    void setYPosition(int yPos);
    void setPosition(int xPos, int yPos);

    /**
     * Getter methods
     */
    int getXPosition();
    int getYPosition();
    CCPoint getCCPosition();
    CCSprite* getSprite();

    /**
     * Strategy pattern for move function
     */

    /**
     * Consider: Zoom methods?
     */
    void zoom(float scaleFactor);

    /**
     * Consider: Fade methods?
     */

    /**
     * Update method. Called every loop.
     */
    virtual void update(CCTime dt);

  private:
    // FIXME: How many of these should be double, rather than int?

    /* All Entities have a current position on the screen */
    int mXPosition;
    int mYPosition; 

    /* Consider: Do all entities have a velocity and acceleration? They
     * probably should if they are all capable of movement */
    int mXVelocity;
    int mYVelocity;
    int mXAcceleration;
    int mYAcceleration;

    float mScaleFactor;

    /* This is the layer that the entity is associated with. The entity is
     * responsible for adding and removing its sprite from the layer */
    CCLayer * mLayer;
    CCSprite * mSprite;

    //FIXME: temp variables for testing things. should be removed
    bool mEnlarging;
};

#endif
