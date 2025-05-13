#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.0f);
    Point outside(5.0f, 5.0f);
    Point edge(2.5f, 0.0f);

    std::cout << "Point inside: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point outside: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl;

    return 0;
}
