#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "Types.h"

/* FIXME: Cannot use entity as argument since Entity uses Physics - it's
 * circular. Should create a struct which holds all the necessary properties
 * and give one to Entity. This will require changes to the implementation of
 * the Physics methods. Should probably use PhysicalProperties as the argument
 * for all methods as it makes them more versatile
 * */

/* *
 * Here are gathered the various regimes for calculating forces at work on a
 * body. These are set up to be interchangeable at runtime. They return a
 * cartesian denoting the forces acting upon the Entity passed in,measured in
 * Newtons.
 * */
namespace Physics
{

  //---Models for calculating forces
  typedef Cartesian (*forcesModel)(const PhysicalProperties* properties);

  /* *
   * The entity is being repelled by a magnet.
   *
   * This implementation uses the classical model of calculating magnetic
   * forces, discussed here:
   * http://en.wikipedia.org/wiki/Force_between_magnets#Force_between_two_magnetic_poles
   *
   * */
  Cartesian classicalMagnetism(const PhysicalProperties* properties);

  /* *
   * The entity falls to earth under the forces of gravity and air resistance.
   *
   * This implementation uses the constant gravitational field strength and the
   * model of air resistance described here:
   *
   * */
  Cartesian classicalGravity(const PhysicalProperties* properties);


  //---Models for calculating acceleration
  typedef Cartesian (*accelerationModel)(Cartesian forces, double mass);

  /* *
   * Newton's second law
   * Force = mass * acceleration
   */
  Cartesian classicalAcceleration(Cartesian forces, double mass);


  //---Models for calculating velocity
  typedef Cartesian (*velocityModel)(Cartesian initialVelocity, 
      Cartesian acceleration, double dt);

  /* *
   * SUVAT equation
   * Final velocity = acceleration * time + initial velocity
   * */
  Cartesian classicalVelocity(Cartesian initialVelocity,
      Cartesian acceleration, double dt);


  //---Models for calculating displacement
  typedef Cartesian (*displacementModel)(Cartesian velocity, 
      Cartesian acceleraion,double dt);

  /* *
   * SUVAT equation
   * */
  Cartesian classicalDisplacement(Cartesian velocity, 
      Cartesian acceleration, double dt);

  //---Utility methods
  double calculateMagneticForce(const double permeability,
      const double mag1, const double mag2, const double distance);
}

#endif
