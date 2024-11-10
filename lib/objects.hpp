#ifndef CURVES3D_OBJECTS
#define CURVES3D_OBJECTS

#include <ostream>

#include "base.hpp"

namespace curves3d {
   class Ellipse : public Curve3d
   {
     private:
      float _radiusX, _radiusY;

     public:
      Ellipse(float radiusX, float radiusY);

      float radiusX() const;
      float& radiusX();
      float radiusY() const;
      float& radiusY();
      virtual Point3d getPoint(float t) const override;
      virtual Point3d getFirstDerivative(float t) const override;
      virtual std::string toString() const override;

      ~Ellipse();
   };

   class Circle : public Curve3d
   {
     private:
      float _radius;

     public:
      Circle(float radius);

      float radius() const;
      float& radius();
      virtual Point3d getPoint(float t) const override;
      virtual Point3d getFirstDerivative(float t) const override;
      virtual std::string toString() const override;

      ~Circle();
   };

   class Helix : public Circle
   {
     private:
      float _step;

     public:
      Helix(float radius, float step);

      virtual Point3d getFirstDerivative(float t) const override;
      virtual std::string toString() const override;

      ~Helix();
   };

   template<class T,
            typename std::enable_if_t<std::is_base_of_v<Curve3d, T>>>
   std::ostream& operator<<(std::ostream& out, const T& object)
   {
      return out << static_cast<const Curve3d&>(object);
   }
} // namespace curves3d

#endif // CURVES3D_OBJECTS
