#include "fractol.h"

int	ft_julia(double x, double y, t_frac *frac)
{
	int		i;
	int		max_iterations;
	double	xtmp;

	i = 1;
	frac->z_re = (x) / ((_WIDTH / 4) * frac->zoom);
	frac->z_im = (y) / ((_HEIGHT / 4) * frac->zoom);
	max_iterations = 120;
	while (i < max_iterations && (frac->z_re * frac->z_re) + (frac->z_im * frac->z_im) <= 4)
	{
		xtmp = (frac->z_re * frac->z_re) - (frac->z_im * frac->z_im) + frac->c_re;
		frac->z_im = 2 * frac->z_re * frac->z_im + frac->c_im;
		frac->z_re = xtmp;
		i++;
	}
	return (ft_hsv_to_rgb(i, 0.1));
}
