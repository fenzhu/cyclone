#include <assert.h>

#include "particle.h"

using namespace cyclone;

void Particle::integrate(real duration)
{
    assert(duration > 0.0);

    // update linear position
    position.addScaledVector(velocity, duration);

    // calculate acc from force
    Vector3 acc = acceleration;
    acc.addScaledVector(forceAccum, inverseMass);

    // update linear velocity
    velocity.addScaledVector(acc, duration);

    // impose drag
    velocity *= real_pow(damping, duration);
}