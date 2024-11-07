#include "base.hpp"

namespace curve3d
{
   bool Point3d::isValidCoordinate(float value)
   {
      return value != std::numeric_limits<float>::infinity() && value != std::numeric_limits<float>::signaling_NaN() && value != -0.0F && value != -std::numeric_limits<float>::infinity();
   }
} // namespace curve3d
