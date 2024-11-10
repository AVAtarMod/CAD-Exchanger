#include "objects.hpp"
#include "core.hpp"

#include <cmath>

namespace curves3d {
   static void validateRadius(float val, std::string label)
   {
      if (!Point3d::isValidCoordinate(val) || val <= 0.0F)
         throw std::invalid_argument("cannot construct Ellipse by " +
                                     label + "=" +
                                     std::to_string(val));
   }
   Ellipse::Ellipse(float radiusX, float radiusY)
   {
      validateRadius(radiusX, "radiusX");
      validateRadius(radiusY, "radiusY");
      _radiusX = radiusX;
      _radiusY = radiusY;
   }

   float Ellipse::radiusX() const
   {
      return _radiusX;
   }
   float& Ellipse::radiusX()
   {
      return _radiusX;
   }
   float Ellipse::radiusY() const
   {
      return _radiusY;
   }
   float& Ellipse::radiusY()
   {
      return _radiusY;
   }
   Point3d Ellipse::getPoint(float t) const
   {
      return Point3d(
        ellipse_x(t, _radiusX), ellipse_y(t, _radiusY), ellipse_z(t));
   }
   Point3d Ellipse::getFirstDerivative(float t) const
   {
      return Point3d(ellipse_FirstDerivative_x(t, _radiusX),
                     ellipse_FirstDerivative_y(t, _radiusY),
                     ellipse_FirstDerivative_z(t));
   }
   std::string Ellipse::toString() const
   {
      return "Ellipse(rX=" + std::to_string(_radiusX) +
             " rY=" + std::to_string(_radiusY) + ")";
   }
   Ellipse::~Ellipse() {}

   Circle::Circle(float radius)
   {
      validateRadius(radius, "radius");
      _radius = radius;
   }
   float Circle::radius() const
   {
      return _radius;
   }
   float& Circle::radius()
   {
      return _radius;
   }
   Point3d Circle::getPoint(float t) const
   {
      return Point3d(
        circle_x(t, _radius), circle_y(t, _radius), circle_z(t));
   }
   Point3d Circle::getFirstDerivative(float t) const
   {
      return Point3d(circle_FirstDerivative_x(t, _radius),
                     circle_FirstDerivative_y(t, _radius),
                     circle_FirstDerivative_z(t));
   }
   std::string Circle::toString() const
   {
      return "Circle(r=" + std::to_string(_radius) + ")";
   }
   Circle::~Circle() {}

   Helix::Helix(float radius, float step) : Circle(radius)
   {
      if (!Point3d::isValidCoordinate(step))
         throw std::invalid_argument(
           "cannot construct Helix with step=" +
           std::to_string(step));
      _step = step;
   }

   Point3d Helix::getFirstDerivative(float t) const
   {
      return Point3d(helix_FirstDerivative_x(t, radius()),
                     helix_FirstDerivative_y(t, radius()),
                     helix_FirstDerivative_z(t, _step));
   }
   std::string Helix::toString() const
   {
      return "Helix(r=" + std::to_string(radius()) +
             ", step=" + std::to_string(_step) + ")";
   }
   Helix::~Helix() {}
} // namespace curves3d
