#include <math.h>

#include "precision.h"

namespace cyclone
{

    class Vector3
    {
    private:
        /* padding to ensure 4-wort alignment */
        real pad;

    public:
        real x;
        real y;
        real z;

        /* default constructor create zero vector */
        Vector3() : x(0), y(0), z(0) {}

        Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

        ~Vector3();

        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }

        real magnitude() const
        {
            return real_sqrt(x * x + y * y + z * z);
        }

        real squareMagnitude() const
        {
            return x * x + y * y + z * z;
        }

        void normalize()
        {
            real l = magnitude();
            if (l > 0)
            {
                (*this) *= ((real)l) / l;
            }
        }
    };

}