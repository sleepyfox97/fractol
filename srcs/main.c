#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_frac	frac;

	if (argc == 2 || argc == 4)
	{
		ft_initialize(argc, argv, &frac);
		frac.mlx_ptr = mlx_init();
		frac.win_ptr = mlx_new_window(frac.mlx_ptr, _WIDTH, _HEIGHT, "fractol");
		frac.data.img = mlx_new_image(frac.mlx_ptr, _WIDTH, _HEIGHT);
		frac.data.addr = mlx_get_data_addr(frac.data.img,
				&(frac.data.bits_per_pixel), &(frac.data.line_length),
				&(frac.data.endian));
        ft_show(&frac);
		ft_use_mlx(&frac);
	}
	else
		ft_error();
	return (0);
}

void	ft_initialize(int argc, char **argv, t_frac *frac)
{
	frac->zoom = 1;
	frac->c_x = _WIDTH / 2;
	frac->c_y = _HEIGHT / 2;
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
		frac->type = _MANDELBR;
	else if (!ft_strcmp(argv[1], "Julia") && argc == 4
		&& ft_is_float(argv[2]) && ft_is_float(argv[3]))
	{
		frac->type = _JULIA;
		ft_atof(argv[2], 0, &(frac->c_re));
		ft_atof(argv[3], 0, &(frac->c_im));
	}
	else if (!ft_strcmp(argv[1], "Perpen") && argc == 4
		&& ft_is_float(argv[2]) && ft_is_float(argv[3]))
	{
		frac->type = _PERPEN;
		ft_atof(argv[2], 0, &(frac->c_re));
		ft_atof(argv[3], 0, &(frac->c_im));
	}
	else
		ft_error();
}
