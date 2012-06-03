#include "Entity.h"

Entity::Entity(const char * imgFile, double xPos, double yPos, CCLayer* pLayer)
  :
    m_mass(1),
    m_magnetism(1),
    m_layer(pLayer),
    fp_calculateForces(Physics::classicalMagnetism),
    fp_calculateAcceleration(Physics::classicalAcceleration),
    fp_calculateVelocity(Physics::classicalVelocity),
    fp_calculateDisplacement(Physics::classicalDisplacement),
    m_scaleFactor(1)
{
  Cartesian pos;
  pos.x = xPos;
  pos.y = yPos;
  setPosition(pos);
  setAcceleration(0,0);
  setVelocity(0,0);
  m_propulsion.x = 0;
  m_propulsion.y = 0;
  m_sprite = CCSprite::spriteWithFile(imgFile);
  m_sprite->setPosition(ccp(m_position.x, m_position.y));
  m_layer->addChild(m_sprite, 0);
}

Entity::~Entity()
{
}

void Entity::update(double dt)
{
  // TODO: Needs updating in light of NOTES
  // Update acceleration, velocity and position
  m_acceleration = fp_calculateAcceleration(fp_calculateForces(m_properties), 
                                            m_mass);

  m_velocity = fp_calculateVelocity(m_velocity, m_acceleration, dt);

  Cartesian displacement = fp_calculateDisplacement(m_velocity, 
                                                    m_acceleration, dt);

  m_position.x += displacement.x;
  m_position.y += displacement.y;

  // Update sprite position and distance to goal accordingly.
  updateSpritePosition();
  updateDistanceToGoal(displacement);
}

void Entity::updateSpritePosition()
{
  m_sprite->setPosition(ccp(m_position.x, m_position.y));
}

void Entity::updateDistanceToGoal(Cartesian displacement)
{
  m_distanceToGoal.x += displacement.x;
  m_distanceToGoal.y += displacement.y;
}
