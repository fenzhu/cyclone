#include "core.h"

namespace cyclone
{
    class Particle
    {
    public:
        Vector3 position;

        Vector3 velocity;

        Vector3 acceleration;

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
    };
}
