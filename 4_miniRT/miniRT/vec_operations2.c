#include "miniRT.h"

t_vec vec(double x, double y, double z)
{
	t_vec out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

// 벡터의 내적
double	vec_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

// 벡터의 외적
t_vec	vec_cross(t_vec *v1, t_vec *v2)
{
	t_vec	out;

	out.x = v1->y * v2->z + v1->z * v2->y;
	out.y = v1->z * v2->x + v1->x * v2->z;
	out.z = v1->x * v2->y + v1->y * v2->x;
	return (out);
}

t_vec vec_unit(t_vec v)
{
	double len;

	len = vec_length(v);
	return (vec(v.x / len, v.y / len ,v.z / len));
}
