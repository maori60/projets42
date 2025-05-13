#include "Point.hpp"

static Fixed area(Point const& p1, Point const& p2, Point const& p3) {
    return Fixed(
        (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
         p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
         p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f
    ).toFloat() < 0 ? Fixed(-1) * Fixed(
        (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
         p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
         p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f
    ) : Fixed(
        (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
         p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
         p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed total = area(a, b, c);
    Fixed a1 = area(point, b, c);
    Fixed a2 = area(a, point, c);
    Fixed a3 = area(a, b, point);

    if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
        return false;

    return (total == a1 + a2 + a3);
}
