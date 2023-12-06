#include "minirt.h"

int main(int argc, char *argv[])
{
	t_view view;
	t_world world;

	view = new_view(WIDTH, HEIGHT, new_vector(0, 0, 0)); // camera position : (0, 0, 0)
	init_world(&world);
	read_file(&world, argc, argv);

	rendering(&view, &world);
}
