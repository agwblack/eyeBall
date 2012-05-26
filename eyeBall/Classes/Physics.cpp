#include "Physics.h"

//---Forces

/**
 * Calculates forces as if repelled by magnet - classical
 * Force = (mu * qm1 * qm2) / (4 * pi * r-squared)
 *  where:
      - mu = permeability of intervening medium (tesla-meter per ampere)
      - qm1, qm2 = magnitudes of magnetic poles (ampere-meter)
      - r = separation (meter)
   http://en.wikipedia.org/wiki/Force_between_magnets#Force_between_two_magnetic_poles
 */
Cartesian Physics::classicalMagnetism(const Entity* ent)
{
  Cartesian f;
  // "Environmental variables" determined by the state of the level.
  const double permeability = 1; // Makes sense to have this as changeable
  const double goalMagnetism = 1; // should probably just be a constant

  f.x = ent->propulsion().x - calculateMagneticForce(permeability, 
      ent->magnetism(), goalMagnetism, ent->distanceToGoal().x);
  f.y = ent->propulsion().y - calculateMagneticForce(permeability, 
      ent->magnetism(), goalMagnetism, ent->distanceToGoal().y);
  return f;
}

Cartesian Physics::classicalGravity(double a, double b)
{
  Cartesian f;
  f.x = 2;
  f.y = 2;
  return f;
}

//---Acceleration
Cartesian Physics::classicalAcceleration(Cartesian forces, double mass)
{
  Cartesian acc;
  acc.x = forces.x / mass;
  acc.y = forces.y / mass;
  return acc;
}

//---Velocity
Cartesian Physics::classicalVeloctiy(Cartesian initialVelocity, 
    Cartesian acceleration, double dt)
{
  Cartesian finalVel;
  finalVel.x  = acceleration.x * dt - initialVelocity.x;
  finalVel.y  = acceleration.y * dt - initialVelocity.y;
  return finalVel;
}

//---Displacement
Cartesian Physics::classicalDisplacement(Cartesian velocity,
    Cartesian acceleration, double dt)
{
  Cartesian dis;
  dis.x = velocity.x * dt - ((acceleration.x * dt * dt) / 2);
  dis.y = velocity.y * dt - ((acceleration.y * dt * dt) / 2);
  return dis;
}

//---Utility methods
double Physics::calculateMagneticForce(const double permeability,
    const double mag1, const double mag2, const double distance)
{
  return (permeability * mag1 * mag2) / (4 * 3.14 * distance);
}
