#include "test_quadratic_equation.h"

START_TEST(test_solve_equation_1) {
  double a = 1;
  double b = 2;
  double c = 1;
  quadratic_equation_result result = solve_equation(a, b, c);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root_1, -1.0, 1e-6);
  ck_assert_double_eq_tol(result.root_2, -1.0, 1e-6);
}

START_TEST(test_solve_equation_2) {
  double a = 2;
  double b = -5;
  double c = 3;
  quadratic_equation_result result = solve_equation(a, b, c);
  ck_assert_int_eq(result.num_roots, 2);
  ck_assert_double_eq_tol(result.root_1, 1.5, 1e-6);
  ck_assert_double_eq_tol(result.root_2, 1, 1e-6);
}

START_TEST(test_solve_equation_3) {
  double a = 1;
  double b = 3;
  double c = 3;
  quadratic_equation_result result = solve_equation(a, b, c);
  ck_assert_int_eq(result.num_roots, 0);
  ck_assert_double_eq_tol(result.root_1, 0, 1e-6);
  ck_assert_double_eq_tol(result.root_2, 0, 1e-6);
}

START_TEST(test_solve_equation_4) {
  double a = 1;
  double b = 2;
  double c = 4;
  quadratic_equation_result result = solve_equation(a, b, c);
  ck_assert_int_eq(result.num_roots, 0);
  ck_assert_double_eq_tol(result.root_1, 0, 1e-6);
  ck_assert_double_eq_tol(result.root_2, 0, 1e-6);
}

int main(void) {
  int number_faild = 0;
  Suite *s = quadratic_equation_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_faild = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_faild == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *quadratic_equation_suite(void) {
  Suite *s = suite_create("quadratic_equation");

  TCase *tc_solve_equation = tcase_create("solve_equation");
  tcase_add_test(tc_solve_equation, test_solve_equation_1);
  tcase_add_test(tc_solve_equation, test_solve_equation_2);
  tcase_add_test(tc_solve_equation, test_solve_equation_3);
  tcase_add_test(tc_solve_equation, test_solve_equation_4);
  suite_add_tcase(s, tc_solve_equation);
  return s;
}