
#include <cmath>
#include <iostream>

#ifndef VEC3_H
#define VEC3_H

class Vec3; 
Vec3 operator/(const Vec3&, double); 

#define vec3_operator_overload(op_name)            \
    inline Vec3 &operator op_name(const Vec3 &rhs) \
    {                                              \
        x op_name rhs.x;                           \
        y op_name rhs.y;                           \
        z op_name rhs.z;                           \
        return *this;                              \
    }

class Vec3
{

public:
    inline Vec3() {}
    inline Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    vec3_operator_overload(+=);
    vec3_operator_overload(-=);
    vec3_operator_overload(*=);
    vec3_operator_overload(/=);

    inline Vec3 operator-() const { return Vec3(-x, -y, -z); };

    inline double operator[](size_t i) const { return (double[]){x, y, z}[i]; };
    inline double &operator[](size_t i) { return *(double *[]){&x, &y, &z}[i]; };

    inline double dot(const Vec3 &rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    inline Vec3 cross(const Vec3 &other) const
    {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }

    inline Vec3 get_unit_vec() const {
        return *this / magnitude(); 
    }

    inline double magnitude() const
    {
        return std::sqrt(dot(*this));
    }

    double x, y, z;
};

using point3 = Vec3;
using color = Vec3;

#undef vec3_operator

// Utility functions below

inline std::ostream &operator<<(std::ostream &os, const Vec3 &v)
{
    return os << v.x << " " << v.y << " " << v.z << " ";
}

inline Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs)
{
    return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs)
{
    return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline Vec3 operator*(const Vec3 &lhs, const Vec3 &rhs)
{
    return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline Vec3 operator*(const double x, const Vec3 &rhs)
{
    return Vec3(x * rhs.x, x * rhs.y, x * rhs.z);
}

inline Vec3 operator*(const Vec3 &lhs, const double x)
{
    return x * lhs;
}

inline Vec3 operator/(const Vec3 &lhs, const double x)
{
    return (1 / x) * lhs;
}

inline double dot(const Vec3 &lhs, const Vec3 &rhs)
{
    return lhs.dot(rhs);
}

inline Vec3 cross(const Vec3 & lhs, const Vec3 & rhs){
    return lhs.cross(rhs); 
}

inline Vec3 unit(const Vec3 & v){
    return v.get_unit_vec(); 
}

#endif