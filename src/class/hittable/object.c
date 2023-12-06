#include "minirt.h"

t_hittable	*new_object(char **tabulate)
{
	t_hittable	*object;
	char		*id;

	id = tabulate[0];
	object = malloc(sizeof(t_hittable));
	if (id == "sp")
		object = new_sphere(tabulate);
	else if (id == "pl")
		object = new_plane(tabulate);
	else if (id == "cy")
		object = new_cylinder(tabulate);
	else
		return (NULL);
	object->next = NULL;
	return (object);
}