#include <limits>
#include <stdexcept>
#include <string_view>

namespace curves3d
{
   class Point3d
   {
   private:
      float _x, _y, _z;

      static bool isValidCoordinate(float value);
      static void validateCoordinate(float value, std::string_view param_name)
      {
         if (!isValidCoordinate(value))
         {
            auto msg = "cannot construct Point3d by " + std::string(param_name) + "=" + std::to_string(value);
            throw std::runtime_error(msg);
         }
      }

   public:
      Point3d(float x = 0, float y = 0, float z = 0)
      {
         validateCoordinate(x, "x");
         validateCoordinate(y, "y");
         validateCoordinate(z, "z");

         _x = x, _y = y, _z = z;
      }
   };
   class Object3d
   {
   public:
      Object3d(/* args */);
      ~Object3d();
   };
} // namespace curves3d
