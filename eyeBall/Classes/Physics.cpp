#include "Physics.h"

Physics::Forces Physics::classicalMagnetism(const Entity* ent)
{
  Physics::Forces f;
  f.x = 1;
  f.y = 1;
  return f;
}

Physics::Forces Physics::classicalGravity(double a, double b)
{
  Physics::Forces f;
  f.x = 2;
  f.y = 2;
  return f;
}
