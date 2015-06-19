#ifndef _INC_VECTOR2
#define _INC_VECTOR2


struct tagvector2
{
	union vector2_value
		{
		float v[2];
		struct vector2_xy
			{
			float x, y;
			};
		};
};


HYPAPI int vector2_equals(const vector2 *self, const vector2 *vT);

HYPAPI vector2 * vector2_zero(vector2 *self);
HYPAPI vector2 * vector2_set(vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_setf2(vector2 *self, float xT, float yT);
HYPAPI vector2 * vector2_negate(vector2 *self);
HYPAPI vector2 * vector2_add(vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_addf(vector2 *self, float fT);
HYPAPI vector2 * vector2_subtract(vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_subtractf(vector2 *self, float fT);
HYPAPI vector2 * vector2_multiply(vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_multiplyf(vector2 *self, float fT);
HYPAPI vector2 * vector2_divide(vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_dividef(vector2 *self, float fT);

HYPAPI vector2 * vector2_normalize(vector2 *self);
HYPAPI float vector2_magnitude(const vector2 *self);
HYPAPI float vector2_distance(const vector2 *v1, const vector2 *v2);

HYPAPI float vector2_dot_product(const vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_cross_product(vector2 *vR, const vector2 *vT1, const vector2 *vT2);

HYPAPI float vector2_angle_between(const vector2 *self, const vector2 *vT);
HYPAPI vector2 * vector2_find_normal_axis_between(vector2 *vR, const vector2 *vT1, const vector2 *vT2);

/* the length is the same as "magnitude" */
#define vector2_length(v) vector2_magnitude(v)

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* BETA aliases */
#define vec2 vector2

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* _INC_VECTOR2 */
