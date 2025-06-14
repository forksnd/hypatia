/* SPDX-License-Identifier: MIT */

static char *test_vector4_set(void)
{
	struct vector4 v1, v2;
	
	/* Test vector4_setf4 */
	vector4_setf4(&v1, 1.0f, 2.0f, 3.0f, 4.0f);
	
	test_assert(scalar_equalsf(v1.x, 1.0f));
	test_assert(scalar_equalsf(v1.y, 2.0f));
	test_assert(scalar_equalsf(v1.z, 3.0f));
	test_assert(scalar_equalsf(v1.w, 4.0f));
	
	/* Test vector4_set - copying from another vector4 */
	vector4_set(&v2, &v1);
	
	test_assert(scalar_equalsf(v2.x, 1.0f));
	test_assert(scalar_equalsf(v2.y, 2.0f));
	test_assert(scalar_equalsf(v2.z, 3.0f));
	test_assert(scalar_equalsf(v2.w, 4.0f));
	
	/* Test that all components are properly copied */
	test_assert(vector4_equals(&v1, &v2));
	
	return NULL;
}

static char *test_vector4_zero(void)
{
	struct vector4 v;
	
	vector4_zero(&v);
	
	test_assert(scalar_equalsf(v.x, 0.0f));
	test_assert(scalar_equalsf(v.y, 0.0f));
	test_assert(scalar_equalsf(v.z, 0.0f));
	test_assert(scalar_equalsf(v.w, 0.0f));
	
	return NULL;
}

static char *vector4_all_tests(void)
{
	run_test(test_vector4_set);
	run_test(test_vector4_zero);
	
	return NULL;
}