#include "core.h"

namespace cyclone
{
    class Particle
    {
    public:
        /*
        the inverse of mass
        0 -> infinite mass, immovable
        infinite -> 0 mass
        */
        real inverseMass;

        /*
        damping is required to remove energy added through numerical instability in the integrator
        */
        real damping;

        Vector3 position;

        Vector3 velocity;

        Vector3 acceleration;

        Vector3 forceAccum;

        void integrate(real duration);
    };
}
