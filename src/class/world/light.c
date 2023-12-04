#include "world.h"

t_light	*new_light(char **tabulate)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	/* todo: split double, split int 만들기*/
	light->origin = new_vector(ft_split_double(tabulate[1]));
	light->bright_ratio = ft_atof(tabulate[2]);
	if (tabulate[3])
		light->color = new_color(ft_split_int(tabulate[3]));
	light->next = NULL;
	return light;
}

// t_light *new_light(t_vector origin, t_color color, double bright_ratio)
// {
// 	t_light *light;

// 	light = malloc(sizeof(t_light));
// 	light->origin = origin;
// 	light->color = color;
// 	light->bright_ratio = bright_ratio;
// 	light->next = NULL;
// 	return light;
// }
// tabulate["ID", "coord", "brightness", "RGB"];