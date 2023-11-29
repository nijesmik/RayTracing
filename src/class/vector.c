#include "class.h"

t_vector new_vector(double x, double y, double z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}

t_vector add_vector(t_vector v1, t_vector v2)
{
	t_vector vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return vector;
}

t_vector subtract_vector(t_vector v1, t_vector v2)
{
	t_vector vector;

	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return vector;
}