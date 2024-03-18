#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>
#include <stdio.h>

/**
 * The result of the quadratic equation.
 *
 * @param num_roots number of roots
 * @param root_1 first root
 * @param root_2 second root
 */
typedef struct {
  int num_roots;
  double root_1;
  double root_2;
} quadratic_equation_result;

quadratic_equation_result solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H