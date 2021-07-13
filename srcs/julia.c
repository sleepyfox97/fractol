#include "fractol.h"

int	ft_julia(double x, double y, t_frac *frac)
{
	int		i;
	int		max_iterations;
	double	xtmp;

	i = 1;
	frac->z_re = (x - (frac->c_x)) / ((_WIDTH / 4) * frac->zoom);
	frac->z_im = (y - (frac->c_y)) / ((_HEIGHT / 4) * frac->zoom);
	max_iterations = 255;
	while (i < max_iterations && pow(frac->z_re, 2) + pow(frac->z_im, 2) <= 4)
	{
		xtmp = pow(frac->z_re, 2) - pow(frac->z_im, 2) + frac->c_re;
		frac->z_im = 2 * frac->z_re * frac->z_im + frac->c_im;
		frac->z_re = xtmp;
		i++;
	}
	return (ft_hsv_to_rgb(60, i % 5, 0.1));
}
