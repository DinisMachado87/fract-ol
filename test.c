#include "minilibx-linux/mlx.h"

int	main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_image(mlx, 1920, 1080);
	(void)mlx_win;
}
