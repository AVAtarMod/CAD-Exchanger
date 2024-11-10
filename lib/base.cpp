#include "base.hpp"

namespace curves3d {
   bool Point3d::isValidCoordinate(float value)
   {
      return value != std::numeric_limits<float>::infinity() &&
             value != std::numeric_limits<float>::signaling_NaN() &&
             value != -std::numeric_limits<float>::infinity();
   }
   void Point3d::validateCoordinate(float value,
                                    std::string_view param_name)
   {
      if (!isValidCoordinate(value)) {
         auto msg = "cannot construct Point3d by " +
                    std::string(param_name) + "=" +
                    std::to_string(value);
         throw std::runtime_error(msg);
      }
   }
   Point3d::Point3d(float x, float y, float z)
   {
      validateCoordinate(x, "x");
      validateCoordinate(y, "y");
      validateCoordinate(z, "z");

      _x = x, _y = y, _z = z;
   }
   float Point3d::x() const
   {
      return _x;
   }
   float Point3d::y() const
   {
      return _y;
   }
   float Point3d::z() const
   {
      return _z;
   }
   void Point3d::validateSetterArgument(float value,
                                        std::string label)
   {
      if (!isValidCoordinate(value))
         throw std::invalid_argument(
           "cannot set " + label +
           " coordinate of Point3d with value=" +
           std::to_string(value));
   }
   Point3d& Point3d::x(float value)
   {
      validateSetterArgument(value, "x");
      _x = value;
      return *this;
   }
   Point3d& Point3d::y(float value)
   {
      validateSetterArgument(value, "y");
      _y = value;
      return *this;
   }
   Point3d& Point3d::z(float value)
   {
      validateSetterArgument(value, "z");
      _z = value;
      return *this;
   }

   std::ostream& operator<<(std::ostream& out, const Point3d& object)
   {
      out << "(x=" << object.x() << ", y=" << object.y()
          << ", z=" << object.z() << ")";
      return out;
   }

   Curve3d::~Curve3d() {};

   std::ostream& operator<<(std::ostream& out, const Curve3d& object)
   {
      out << object.toString();
      return out;
   }
} // namespace curves3d
