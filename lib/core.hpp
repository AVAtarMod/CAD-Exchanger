#ifndef CURVES3D_CORE
#define CURVES3D_CORE

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

float ellipse_x(float t, float radiusX);
float ellipse_y(float t, float radiusY);
float ellipse_z(float t);
float ellipse_FirstDerivative_x(float t, float radiusX);
float ellipse_FirstDerivative_y(float t, float radiusY);
float ellipse_FirstDerivative_z(float t);

float circle_x(float t, float radius);
float circle_y(float t, float radius);
float circle_z(float t);
float circle_FirstDerivative_x(float t, float radius);
float circle_FirstDerivative_y(float t, float radius);
float circle_FirstDerivative_z(float t);

float helix_x(float t, float radius);
float helix_y(float t, float radius);
float helix_z(float t, float step);
float helix_FirstDerivative_x(float t, float radius);
float helix_FirstDerivative_y(float t, float radius);
float helix_FirstDerivative_z(float t, float step);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // CURVES3D_CORE
