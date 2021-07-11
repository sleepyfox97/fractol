#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_frac	frac;
	if (argc == 2 || argc == 4)
	{
		ft_initialize(argc, argv, &frac);
		ft_use_mlx(&frac);
	}
	else
		ft_error();
	return (0);
}

void	ft_initialize(int argc, char **argv, t_frac *frac)
{
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
	{
		frac->type = _MANDELBR;
		printf("koko\n");
	}
	else if (!ft_strcmp(argv[1], "Julia") && argc == 4 && ft_is_float(argv[2]) && ft_is_float(argv[3]))
	{
		frac->type = _JULIA;
		ft_atof(argv[2], 0, &(frac->c_re));
		ft_atof(argv[3], 0, &(frac->c_im));
	}
	else
		ft_error();
}

// void	ft_make_img(t_frac *frac)
// {
// 	int	x;
// 	int	y;

// 	while (x < _WIDTH)
// 	{
// 		x = 0;
// 		while (y < _HEIGHT)
// 		{
// 		ft_julia(((double)x - (_WIDTH / 2)) / (double)(_WIDTH / 4), (((double)y - (_WIDTH / 2)) / (double)(_WIDTH / 4)), frac);
// 			y++;
// 		}
// 	}
// 	printf("koko\n");
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_julia(double  x, double y, t_frac *frac)
{
	int i;
	int max_iterations;
	double xtmp;

	i = 1;
	frac->z_re = (x - (_WIDTH / 2)) / (_WIDTH / 3);
	frac->z_im = (y - (_HEIGHT / 2)) / (_HEIGHT / 3);
	max_iterations = 255;
	while(i < max_iterations && pow(frac->z_re, 2) + pow(frac->z_im, 2) <= 4)
	{
		xtmp = pow(frac->z_re, 2) - pow(frac->z_im, 2)+ frac->c_re;
		frac->z_im = 2 * frac->z_re * frac->z_im + frac->c_im;
		frac->z_re = xtmp;
		i++;
	}
	if (i == max_iterations)
		return (i);
	return (i << 16 | i << 8 | i);
}

void	ft_use_mlx(t_frac *frac)
{
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, 600, 600, "test");
	frac->data.img = mlx_new_image(frac->mlx_ptr, 600, 600);
	frac->data.addr = mlx_get_data_addr(frac->data.img, &(frac->data.bits_per_pixel),
		&(frac->data.line_length), &(frac->data.endian));
	//ここまで準備でやっとく
	ft_show(frac);
	mlx_hook(frac->win_ptr, 2, 1L << 0, ft_key_event, frac);
	//mlx_hook(frac->win_ptr, 6, 1L << 6, ft_mmove, frac);
	mlx_mouse_hook(frac->win_ptr, ft_mroll, frac);
	mlx_hook(frac->win_ptr, 33, 1L << 17, ft_click_event, frac);
	mlx_loop(frac->mlx_ptr);
}

void	ft_show(t_frac *frac)
{
	int	x;
	int	y;

	y = 0;
	while (y < _HEIGHT)
	{
		x = 0;
		while (x < _WIDTH)
		{
			my_mlx_pixel_put(&(frac->data), x, 600 - y, ft_julia((double)x, (double)y, frac));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->data.img, 0, 0);
}

int		ft_mmove(int x, int y, t_frac *frac)
{
	printf("x = %d y = %d\n", x, y);
	return (0);
}

int		ft_mroll(int zoom, int x, int y, t_frac *frac)
{
	printf("zoom = %d x = %d y = %d\n", zoom, x, y);
	return (0);
}

int		ft_key_event(int keycode, t_frac *frac)
{
	if (keycode == K_ESC)
		ft_close(frac);
	else
		printf("code = %d\n", keycode);
	return (0);
}

void	ft_close(t_frac *frac)
{
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	exit (0);
	return ;
}

int		ft_click_event(int keycode, t_frac *frac)
{
	printf("code = %d\n", keycode);
	return (0);
}
