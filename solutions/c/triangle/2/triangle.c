#include "triangle.h"

bool is_triangle(triangle_t sides) {
    double half_sum = (sides.a + sides.b + sides.c) / 2.0;
    return sides.a && sides.a <= half_sum
        && sides.b && sides.b <= half_sum
        && sides.c && sides.c <= half_sum;
}

bool is_equilateral(triangle_t sides) {
    return is_triangle(sides) 
        && sides.a == sides.b && sides.a == sides.c;
}

bool is_isosceles(triangle_t sides) {
    return is_triangle(sides) 
        && (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c);
}

bool is_scalene(triangle_t sides) {
    return is_triangle(sides) && !is_isosceles(sides);
}
