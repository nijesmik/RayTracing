#include "minirt.h"
#include "error.h"

int	read_file(t_world *world, int argc, char *argv[])
{
	if (argc != 2)
		return (ERROR_ARGC);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		return (ERROR_FILENAME);
	if (parsing(&world, argv[1]) == FAIL)
		return (ERROR_PARSING);
	check_components(&world);
}
