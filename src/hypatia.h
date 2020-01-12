/* SPDX-License-Identifier: MIT */

#ifndef _INC_HYPATIA
#define _INC_HYPATIA

#include "config.h"


#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER) || defined(WIN32)
#	undef HYPAPI
#	define HYPAPI __declspec(dllexport)
	/* #ifndef HYP_EXPORTS_ON
	 * #else
	 *	#define HYPAPI __declspec(dllimport)
	 * #endif
	 */
#else
#	undef HYPAPI
#	define HYPAPI
#endif

#ifdef HYPATIA_SINGLE_PRECISION_FLOATS
#	define HYP_FLOAT float
#else
#	define HYP_FLOAT double
#endif

#include <math.h> /* sin, cos, acos */
#include <stdlib.h> /* RAND_MAX, rand */
#include <float.h> /*FLT_EPSILON, DBL_EPSILON*/
#include <stdint.h>
#include <stdio.h> /* printf (in the _print* functions) */
#include <memory.h> /* memset */

/**
 * @ingroup _constants
 * @{
 */

/** @brief PI to 100 digits (gets rounded off by the compiler) */
#define HYP_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f
/** @brief Tau to 100 digits, which is 2 * PI */
#define HYP_TAU 6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341359f
/** @brief Half of PI */
#define HYP_PI_HALF 1.5707963267948966f
/** @brief PI * PI */
#define HYP_PI_SQUARED 9.8696044010893586f
/** @brief Log e is the Natural Logarithm in base 10 */
#define HYP_E 2.71828182845904523536028747135266249775724709369995f
/** @brief Radians per Degree = PI/180 */
#define HYP_RAD_PER_DEG 0.0174532925199432957692369076848861f
/** @brief Degrees per Radian = 180/PI */
#define HYP_DEG_PER_RAD 57.2957795130823208767981548141052f
/** @brief PI/180 */
#define HYP_PIOVER180  HYP_RAD_PER_DEG
/** @brief 180/PI */
#define HYP_PIUNDER180 HYP_DEG_PER_RAD
/** @brief Epsilon.  This is the value that is used to determine how much
 * rounding error is tolerated.
 */
#ifdef HYPATIA_SINGLE_PRECISION_FLOATS
#	define HYP_EPSILON 1E-5f
#else
#	define HYP_EPSILON 1E-7
#endif
/*@}*/

/** @brief A macro that returns the minimum of \a a and \a b */
#define HYP_MIN(a, b)  (((a) < (b)) ? (a) : (b))

/** @brief A macro that returns the maximum of \a a and \a b */
#define HYP_MAX(a, b)  (((a) > (b)) ? (b) : (a))

/** @brief A macro that swaps \a a and \a b */
#define HYP_SWAP(a, b) { HYP_FLOAT f = a; a = b; b = f; }

/** @brief A macro that returns a random float point number up to RAND_MAX */
#define HYP_RANDOM_FLOAT (((HYP_FLOAT)rand() - (HYP_FLOAT)rand()) / (HYP_FLOAT)RAND_MAX)

/** @brief A macro that converts an angle in degress to an angle in radians */
#define HYP_DEG_TO_RAD(angle)  ((angle) * HYP_RAD_PER_DEG)

/** @brief A macro that converts an angle in radians to an angle in degrees */
#define HYP_RAD_TO_DEG(radians) ((radians) * HYP_DEG_PER_RAD)

/** @brief A macro that squares a value squared */
#define HYP_SQUARE(number) (number * number)

/** @brief A macro that finds the square root of a value */
#define HYP_SQRT(number) ((HYP_FLOAT)sqrt(number))

/** @brief A macro that returns the absolute value */
#define HYP_ABS(value) (((value) < 0) ? -(value) : (value))

/** @brief A macro that wraps a value around and around in a range */
#define HYP_WRAP(value, start, limit) (value = fmod(start + (value - start), (limit - start)))

/** @brief A macro that constrains the value between two limits \a a and \a b */
#define HYP_CLAMP(value, start, limit) (value = ((value < start) ? start : (value > limit) ? limit : value))

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* forward declarations */
struct vector2;
struct vector3;
struct vector4;
struct matrix3;
struct matrix4;
struct quaternion;

#define HYP_REF_VECTOR2_ZERO 0
#define HYP_REF_VECTOR2_UNIT_X 1
#define HYP_REF_VECTOR2_UNIT_Y 2
#define HYP_REF_VECTOR2_UNIT_X_NEGATIVE 3
#define HYP_REF_VECTOR2_UNIT_Y_NEGATIVE 4
#define HYP_REF_VECTOR2_ONE 5

HYPAPI const struct vector2 *vector2_get_reference_vector2(int id);

#define HYP_REF_VECTOR3_ZERO 0
#define HYP_REF_VECTOR3_UNIT_X 1
#define HYP_REF_VECTOR3_UNIT_Y 2
#define HYP_REF_VECTOR3_UNIT_Z 3
#define HYP_REF_VECTOR3_UNIT_X_NEGATIVE 4
#define HYP_REF_VECTOR3_UNIT_Y_NEGATIVE 5
#define HYP_REF_VECTOR3_UNIT_Z_NEGATIVE 6
#define HYP_REF_VECTOR3_ONE 7

HYPAPI const struct vector3 *vector3_get_reference_vector3(int id);

#define HYP_REF_VECTOR4_ZERO 0
#define HYP_REF_VECTOR4_UNIT_X 1
#define HYP_REF_VECTOR4_UNIT_Y 2
#define HYP_REF_VECTOR4_UNIT_Z 3
#define HYP_REF_VECTOR4_UNIT_X_NEGATIVE 4
#define HYP_REF_VECTOR4_UNIT_Y_NEGATIVE 5
#define HYP_REF_VECTOR4_UNIT_Z_NEGATIVE 6
#define HYP_REF_VECTOR4_ONE 7

HYPAPI const struct vector4 *vector4_get_reference_vector4(int id);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/** @ingroup reference_vectors */
/** @brief {0,0,0} */
#define HYP_VECTOR3_ZERO vector3_get_reference_vector3(HYP_REF_VECTOR3_ZERO)
/** @ingroup reference_vectors */
/** @brief {1,0,0} */
#define HYP_VECTOR3_UNIT_X vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_X)
/** @ingroup reference_vectors */
/** @brief {0,1,0} */
#define HYP_VECTOR3_UNIT_Y vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_Y)
/** @ingroup reference_vectors */
/** @brief {0,0,1} */
#define HYP_VECTOR3_UNIT_Z vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_Z)
/** @ingroup reference_vectors */
/** @brief {-1,0,0} */
#define HYP_VECTOR3_UNIT_X_NEGATIVE vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_X_NEGATIVE)
/** @ingroup reference_vectors */
/** @brief {0,-1,0} */
#define HYP_VECTOR3_UNIT_Y_NEGATIVE vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_Y_NEGATIVE)
/** @ingroup reference_vectors */
/** @brief {0,0,-1} */
#define HYP_VECTOR3_UNIT_Z_NEGATIVE vector3_get_reference_vector3(HYP_REF_VECTOR3_UNIT_Z_NEGATIVE)
/** @ingroup reference_vectors */
/** @brief {1,1,1} */
#define HYP_VECTOR3_ONE vector3_get_reference_vector3(HYP_REF_VECTOR3_ONE)
/* @} */


/** @ingroup reference_vectors */
/** @brief {0,0} */
#define HYP_VECTOR2_ZERO vector2_get_reference_vector2(HYP_REF_VECTOR2_ZERO)
/** @ingroup reference_vectors */
/** @brief {1,0} */
#define HYP_VECTOR2_UNIT_X vector2_get_reference_vector2(HYP_REF_VECTOR2_UNIT_X)
/** @ingroup reference_vectors */
/** @brief {0,1} */
#define HYP_VECTOR2_UNIT_Y vector2_get_reference_vector2(HYP_REF_VECTOR2_UNIT_Y)
/** @ingroup reference_vectors */
/** @brief {-1,0} */
#define HYP_VECTOR2_UNIT_X_NEGATIVE vector2_get_reference_vector2(HYP_REF_VECTOR2_UNIT_X_NEGATIVE)
/** @ingroup reference_vectors */
/** @brief {0,-1} */
#define HYP_VECTOR2_UNIT_Y_NEGATIVE vector2_get_reference_vector2(HYP_REF_VECTOR2_UNIT_Y_NEGATIVE)
/** @ingroup reference_vectors */
/** @brief {1,1} */
#define HYP_VECTOR2_ONE vector2_get_reference_vector2(HYP_REF_VECTOR2_ONE)
/* @} */


HYPAPI short scalar_equalsf(const HYP_FLOAT f1, const HYP_FLOAT f2);
HYPAPI short scalar_equals_epsilonf(const HYP_FLOAT f1, const HYP_FLOAT f2, const HYP_FLOAT epsilon);

#define scalar_equals scalar_equalsf


/**
 * @ingroup trig
 * @{
 */

#define HYP_SIN(x) ((HYP_FLOAT)sin(x))
#define HYP_COS(x) ((HYP_FLOAT)cos(x))
#define HYP_TAN(x) ((HYP_FLOAT)tan(x))
#define HYP_ASIN(x) ((HYP_FLOAT)asin(x))
#define HYP_ACOS(x) ((HYP_FLOAT)acos(x))
#define HYP_ATAN2(y, x) ((HYP_FLOAT)atan2(y, x))
#define HYP_COT(a) (1.0f / HYP_TAN(a))

/* @} */

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"
#include "matrix4.h"
#include "quaternion.h"
#include "experimental.h"

/**
 * @ingroup experimental
 * @{
 */

#define _HYP_SWAP(x, y) do { tmp = x; x = y; y = tmp; } while (0)

HYPAPI void _matrix3_print_with_columnrow_indexer(struct matrix3 *self);
HYPAPI void _matrix3_print_with_rowcolumn_indexer(struct matrix3 *self);
HYPAPI struct matrix3 *_matrix3_set_random(struct matrix3 *self);

HYPAPI void _matrix4_print_with_columnrow_indexer(struct matrix4 *self);
HYPAPI void _matrix4_print_with_rowcolumn_indexer(struct matrix4 *self);
HYPAPI struct matrix4 *_matrix4_set_random(struct matrix4 *self);

HYPAPI void _quaternion_print(const struct quaternion *self);
HYPAPI struct quaternion *_quaternion_set_random(struct quaternion *self);

HYPAPI void _vector3_print(const struct vector3 *self);
HYPAPI struct vector3 *_vector3_set_random(struct vector3 *self);

HYPAPI void _vector2_print(const struct vector2 *self);
HYPAPI struct vector2 *_vector2_set_random(struct vector2 *self);

HYPAPI void _vector4_print(const struct vector4 *self);
HYPAPI struct vector4 *_vector4_set_random(struct vector4 *self);

/* @} */

#endif /* _INC_HYPATIA */
