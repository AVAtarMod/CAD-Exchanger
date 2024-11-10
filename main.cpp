#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "lib/objects.hpp"

typedef std::shared_ptr<curves3d::Curve3d> object_ptr_t;

template<uint32_t min, uint32_t max>
constexpr inline uint32_t range(uint32_t value)
{
   return min + (value % (max + 1 - min));
}

object_ptr_t construct(uint type)
{
   object_ptr_t result;
   static std::mt19937 local_prng = {};
   static std::uniform_real_distribution flt_distrib(2.0F, 12.0F);

   using namespace curves3d;
   switch (type) {
      case 0:
         result = std::make_shared<Circle>(flt_distrib(local_prng));
         break;
      case 1:
         result = std::make_shared<Ellipse>(flt_distrib(local_prng),
                                            flt_distrib(local_prng));
         break;
      case 2:
         result = std::make_shared<Helix>(flt_distrib(local_prng),
                                          flt_distrib(local_prng));
      default:
         break;
   }
   return result;
}

int main(int argc, char const* argv[])
{
   std::mt19937 prng = {};
   std::vector<object_ptr_t> objects(range<6, 15>(prng()));
   objects[0] = construct(0);
   objects[1] = construct(1);
   objects[2] = construct(2);
   for (size_t i = 3; i < objects.size(); ++i) {
      objects[i] = construct(range<0, 2>(prng()));
   }
   std::shuffle(objects.begin(), objects.end(), prng);

   constexpr float val = M_PI / 4;
   for (const auto& i : objects) {
      std::cout << "\t" << *i << " at π/4: " << i->getPoint(val)
                << ", derivative: " << i->getFirstDerivative(val)
                << "\n";
   }
   std::cout << "\n";

   using circle_ptr_t = std::shared_ptr<curves3d::Circle>;
   std::vector<circle_ptr_t> circles;
   for (const auto& i : objects) {
      circle_ptr_t circle =
        std::dynamic_pointer_cast<curves3d::Circle>(i);
      if (circle && typeid(*circle) == typeid(curves3d::Circle)) {
         circles.push_back(circle);
      }
   }
   std::sort(circles.begin(),
             circles.end(),
             [](const circle_ptr_t& left, const circle_ptr_t& right) {
                return left->radius() <= right->radius();
             });

   float radii_sum = 0.0F;
#pragma omp parallel for reduction(+ : radii_sum)
   for (size_t i = 0; i < circles.size(); ++i) {
      radii_sum += circles[i]->radius();
   }
   std::cout << "Sum of radii of circles: " << radii_sum << "\n";
}
