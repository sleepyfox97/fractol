#include "fractol.h"

int	ft_mandelbrot(double x, double y, t_frac *frac)
{
	int		i;
	int		max_iterations;
	double	xtmp;

	i = 0;
	frac->z_re = 0;
	frac->z_im = 0;
	frac->c_re = (x - frac->c_x - 100) / (200 * frac->zoom);
	frac->c_im = (y - frac->c_y) / (200 * frac->zoom);
	max_iterations = 30;
	while (pow(frac->z_re, 2) + pow(frac->z_im, 2) < 10000000000
		&& i < max_iterations)
	{
		xtmp = pow(frac->z_re, 2) - pow(frac->z_im, 2) + frac->c_re;
		frac->z_im = 2 * frac->z_re * frac->z_im + frac->c_im;
		frac->z_re = xtmp;
		i++;
	}
	return ((8 * i));
}
