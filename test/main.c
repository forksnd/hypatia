/* SPDX-License-Identifier: MIT */

#include <stdio.h>
#include <hypatia.h>

#define UNUSED_VARIABLE(x) ((void)(x))

#include "unittest.h"

#include "test_vector2.c"
#include "test_vector3.c"
#include "test_vector4.c"
#include "test_quaternion.c"
#include "test_matrix2.c"
#include "test_matrix3.c"
#include "test_matrix4.c"
#include "test_experimental.c"

int tests_run;
char *test_message;

static char *all_testsuites(void)
{
	printf("quaternion_all_tests\n");
	run_test(quaternion_all_tests);
	printf("matrix2_all_tests\n");
	run_test(matrix2_all_tests);
	printf("matrix3_all_tests\n");
	run_test(matrix3_all_tests);
	printf("matrix4_all_tests\n");
	run_test(matrix4_all_tests);
	printf("vector3_all_tests\n");
	run_test(vector3_all_tests);
	printf("vector4_all_tests\n");
	run_test(vector4_all_tests);
	printf("experimental_all_tests\n");
	run_test(experimental_all_tests);

	return NULL;
}

int main(int argc, char *argv[])
{
	char *result;

	UNUSED_VARIABLE(argc);
	UNUSED_VARIABLE(argv);

	tests_run = 0;
	test_message = 0;

	result = all_testsuites();
	if (result != 0) {
		printf("%s\n", result);
	} else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
