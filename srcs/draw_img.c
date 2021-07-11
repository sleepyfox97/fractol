#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			if (frac->type == _JULIA)
				my_mlx_pixel_put(&(frac->data), x, 600 - y, \
					ft_julia((double)x, (double)y, frac));
			else if (frac->type == _MANDELBR)
				my_mlx_pixel_put(&(frac->data), x, 600 - y, \
					ft_mandelbrot((double)x, (double)y, frac));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr,
		frac->data.img, 0, 0);
}
