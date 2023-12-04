#include "minirt.h"

int	read_file(t_world *world, int argc, char *argv[])
{
	if (argc != 2)
		return ERROR_ARGC;
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		return ERROR_FILENAME;
	parsing(&world, argv[1]);
	check_components(&world);
}
