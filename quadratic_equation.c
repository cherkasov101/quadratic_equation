#include "quadratic_equation.h"

/**
 * Solves the quadratic equation ax^2 + bx + c = 0
 * @param a
 * @param b
 * @param c
 * @return quadratic_equation_result
 */
quadratic_equation_result solve_equation(double a, double b, double c) {
  quadratic_equation_result result;
  double discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    result.num_roots = 2;
    result.root_1 = (-b + sqrt(discriminant)) / (2 * a);
    result.root_2 = (-b - sqrt(discriminant)) / (2 * a);
  } else if (discriminant == 0) {
    result.num_roots = 1;
    result.root_1 = -b / (2 * a);
    result.root_2 = result.root_1;
  } else {
    result.num_roots = 0;
  }

  return result;
}
