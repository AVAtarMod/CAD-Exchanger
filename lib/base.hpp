#ifndef CURVES3D_BASE
#define CURVES3D_BASE

#include <limits>
#include <ostream>
#include <stdexcept>
#include <string_view>

namespace curves3d {
   class Point3d
   {
     private:
      float _x, _y, _z;

      static void validateCoordinate(float value,
                                     std::string_view param_name);
      static void validateSetterArgument(float value,
                                         std::string label);

     public:
      static bool isValidCoordinate(float value);
      float x() const;
      float y() const;
      float z() const;
      Point3d& x(float value);
      Point3d& y(float value);
      Point3d& z(float value);
      Point3d(float x = 0, float y = 0, float z = 0);
   };
   std::ostream& operator<<(std::ostream& out, const Point3d& object);
   class Curve3d
   {
     public:
      virtual Point3d getPoint(float t) const = 0;
      virtual Point3d getFirstDerivative(float t) const = 0;
      virtual std::string toString() const = 0;
      virtual ~Curve3d() = 0;
   };
   std::ostream& operator<<(std::ostream& out, const Curve3d& object);

} // namespace curves3d

#endif // CURVES3D_BASE
