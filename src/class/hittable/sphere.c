#include "hittable.h"

// t_hittable *new_sphere(t_vector center, double radius, t_color color)
// {
// 	t_hittable *sphere;

// 	sphere = malloc(sizeof(t_hittable));
// 	sphere->type = SPHERE;
// 	sphere->center = center;
// 	sphere->radius = radius;
// 	sphere->color = color;
// 	sphere->next = NULL;
// 	return sphere;
// }
t_hittable *new_sphere(char **tabulate)
{
	t_hittable	*sphere;

	sphere = malloc(sizeof(t_hittable));
	/* todo: */
	sphere->type = SPHERE;
	sphere->center = new_vector(ft_split_double(tabulate[1]));
	sphere->radius = ft_atof(tabulate[2]) / 2;
	sphere->color = new_color(ft_split_int(tabulate[3]));
	sphere->next = NULL;
	return (sphere);
}

t_discriminant sp_discriminant(t_ray *ray, t_hittable *sphere)
{
	t_discriminant	d;
	t_vector		oc;
	double			c;
	double			discriminant;

	oc = subtract_vector(ray->origin, sphere->center);
	d.a = dot_product(ray->dir, ray->dir);
	d.half_b = dot_product(ray->dir, oc);
	c = dot_product(oc, oc) - sphere->radius * sphere->radius;
	discriminant = d.half_b * d.half_b - d.a * c;
	d.is_negative = (discriminant < 0);
	d.sqrt_d = sqrt(discriminant);
	return (d);
}
