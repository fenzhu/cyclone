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

        void operator*=(const real value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        Vector3 operator*(const real value) const
        {
            return Vector3(x * value, y * value, z * value);
        }

        void operator+=(const Vector3 &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        Vector3 operator+(const Vector3 &v) const
        {
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        void operator-=(const Vector3 &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        Vector3 operator-(const Vector3 &v) const
        {
            return Vector3(x - v.x, y - v.y, z - v.z);
        }

        void addScaledVector(const Vector3 &v, real scale)
        {
            x += v.x * scale;
            y += v.y * scale;
            z += v.z * scale;
        }

        void componentProductUpdate(const Vector3 &v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
        }

        real scalarProduct(const Vector3 &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        real operator*(const Vector3 &v) const
        {
            return scalarProduct(v);
        }

        Vector3 componentProduct(const Vector3 &v) const
        {
            return Vector3(x * v.x, y * v.y, z * v.z);
        }

        Vector3 vectorProduct(const Vector3 &v) const
        {
            return Vector3(
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x);
        }

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