#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "Entity.h"

/* *
 * Here are gathered the various regimes for calculating forces at work on a
 * body. These are set up to be interchangeable at runtime.
 * */
namespace Physics
{
  /* *
   * Struct which contains force in Newtons in both the horizontal and vertical
   * planes.
   * */
  typedef struct 
  {
    double x;
    double y;
  } Forces;

  // Typedef for function pointer
  typedef Forces (*physicsRegime)(const Entity* ent);

  /* *
   * The entity is being repelled by a magnet.
   *
   * This implementation uses the classical model of calculating magnetic
   * forces, discussed here:
   *
   * */
  Forces classicalMagnetism(const Entity* ent);

  /* *
   * The entity falls to earth under the forces of gravity and air resistance.
   *
   * This implementation uses the constant gravitational field strength and the
   * model of air resistance described here:
   *
   * */
  Forces classicalGravity(const Entity* ent);
}

#endif
