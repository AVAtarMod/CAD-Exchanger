#include "core.hpp"

#include <cmath>

float ellipse_x(float t, float radiusX)
{
   return radiusX * std::cosf(t);
}
float ellipse_y(float t, float radiusY)
{
   return radiusY * std::sinf(t);
}
float ellipse_z(float t)
{
   return 0;
}
float ellipse_FirstDerivative_x(float t, float radiusX)
{
   return -1 * radiusX * std::sinf(t);
}
float ellipse_FirstDerivative_y(float t, float radiusY)
{
   return radiusY * std::cosf(t);
}
float ellipse_FirstDerivative_z(float t)
{
   return 0;
}

float circle_x(float t, float radius)
{
   return radius * std::cosf(t);
}
float circle_y(float t, float radius)
{
   return radius * std::sinf(t);
}
float circle_z(float t)
{
   return 0;
}
float circle_FirstDerivative_x(float t, float radius)
{
   return -1 * radius * std::sinf(t);
}
float circle_FirstDerivative_y(float t, float radius)
{
   return radius * std::cosf(t);
}
float circle_FirstDerivative_z(float t)
{
   return 0;
}

float helix_x(float t, float radius)
{
   return circle_x(t, radius);
}
float helix_y(float t, float radius)
{
   return circle_y(t, radius);
}
float helix_z(float t, float step)
{
   return (t / (2 * M_PI)) * step;
}
float helix_FirstDerivative_x(float t, float radius)
{
   return circle_FirstDerivative_x(t, radius);
}
float helix_FirstDerivative_y(float t, float radius)
{
   return circle_FirstDerivative_y(t, radius);
}
float helix_FirstDerivative_z(float t, float step)
{
   return step / (2 * M_PI);
}
