#include "minirt.h"
#include "error.h"

int	check_components(t_world *world)
{
	/***
	 * count ambient, camera, light, object
	 * ambient, camera = 1
	 * light, object >= 1
	 * 
	 * or free all
	 * 
	 * -> make count variable in world structure
	 * or count in here only
	*/
}

int	read_file(t_world *world, int argc, char *argv[])
{
	if (argc != 2)
		return (ERROR_ARGC);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		return (ERROR_FILENAME);
	if (parsing(&world, argv[1]) == FAIL)
		/* if parsing fail -> free all*/
		return (ERROR_PARSING);
	check_components(&world);
}

