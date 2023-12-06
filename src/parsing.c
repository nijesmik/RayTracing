#include "minirt.h"

int	check_id(char *id)
{
	if (!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || !ft_strcmp(id, "cy"))
		return (ID_OBJECT);
	if (ft_strcmp(id, "L") == 0)
		return (ID_LIGHT);
	/*
	todo: Ambient, Camera

	Ambient lighting is the result of light reflecting off of other objects.
	else if (ft_strcmp(id, "A") == 0)
		return (ID_AMBIENT);
	Camera is the point of view from which the scene is rendered.
	else if (ft_strcmp(id, "c") == 0)
		return (ID_CAMERA);
	*/
	else
		return (FAIL);
}

int	add_component(t_world *world, char **tabulate)
{
	t_hittable	*object;
	t_light		*light;
	char		*id;

	id = check_id(tabulate[0]);
	if (id == ID_OBJECT)
	{
		object = new_object(tabulate);
		if (object == NULL)
			return (FAIL);
		add_object(world, object);
	}
	else if (id == ID_LIGHT)
	{
		light = new_light(tabulate);
		if (light == NULL)
			return (FAIL);
		add_light(world, light);
	}
	else
		return (FAIL);
}

int	parsing(t_world *world, char *filename)
{
	int		fd;
	char	*line;
	char	**tabulate;

	if (ft_open(&fd, filename, O_RDONLY) == FAIL)
		return (FAIL);
	line = get_next_line(fd);
	while (line)
	{
		tabulate = ft_split(line, ' ');
		if (add_component(world, tabulate) == FAIL)
		{
			free(line);
			ft_free_tabulate(tabulate);
			return (FAIL);
		}
		free(line);
		ft_free_tabulate(tabulate);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_close(fd));
}
