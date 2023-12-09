#include "miniRT.h"

t_vec	vec_add(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->x + v2->x;
	out.y = v1->y + v2->y;
	out.z = v1->z + v2->z;
	return (out);
}

t_vec	vec_sub(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->x - v2->x;
	out.y = v1->y - v2->y;
	out.z = v1->z - v2->z;
	return (out);
}

t_vec	vec_mul(t_vec *v1, double t)
{
	t_vec out;

	out.x = v1->x * t;
	out.y = v1->y * t;
	out.z = v1->z * t;
	return (out);
}

t_vec	vec_div(t_vec *v1, double t)
{
	t_vec out;

	out.x = v1->x / t;
	out.y = v1->y / t;
	out.z = v1->z / t;
	return (out);
}

double	vec_length(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// SQuare RooT(제곱근)
double	sqrt(double n)
{
	double	out;
	double	tmp;

	tmp = 0;
	out = n / 2;
	while (out != tmp)
	{
		tmp = out;
		out = ( (n / tmp) + tmp) / 2;
	}
	return (out);
}
