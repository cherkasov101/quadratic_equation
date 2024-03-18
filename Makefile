CC = gcc
FILES = *.h *.c 
FLAGS = -Wall -Werror -Wextra -std=c11
TESTS = tests/*.c tests/*.h
GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lm -lsubunit
else
	TEST_LIBS =-lcheck
endif

all: clean quadratic_equation.a check gcov_report

quadratic_equation.a: clean 
	$(CC) $(FLAGS) -c $(FILES)
	ar rc quadratic_equation.a *.o
	ranlib quadratic_equation.a

quadratic_equation_gcov.a: clean
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(FILES)
	ar rc quadratic_equation_gcov.a *.o
	ranlib quadratic_equation_gcov.a

check:
	$(CC) $(FLAGS) tests/*.c quadratic_equation.a $(TEST_LIBS) -o quadratic_equation_test
	./quadratic_equation_test

gcov_report: quadratic_equation_gcov.a
	$(CC) $(FLAGS) $(GCOVFLAGS) tests/*.c quadratic_equation_gcov.a $(TEST_LIBS) -o quadratic_equation_gcov
	./quadratic_equation_gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html

style:
	clang-format -i $(FILES) $(TESTS)

clean:
	rm -rf report/ *.o *.html *.gcda *.gch *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt quadratic_equation_test quadratic_equation_gcov

.PHONY: all clean
