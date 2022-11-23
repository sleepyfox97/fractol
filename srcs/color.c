#include "fractol.h"

int	ft_hsv_to_rgb(double s, double v)
{
	double	x;
	double	c;
	double	rgb[3];
    int     h;

	c = v * s;
	h = 3;
	if ((int)floor(h) % 2 == 1)
		x = c * (1 - fabs(h - floor(h)));
	else
		x = c * (1 - fabs(h - floor(h) - 1));
	if (h == 0)
		ft_set_rgb(rgb, c, x, 0);
	else if (h == 1)
		ft_set_rgb(rgb, x, c, 0);
	else if (h == 2)
		ft_set_rgb(rgb, 0, c, x);
	else if (h == 3)
		ft_set_rgb(rgb, 0, x, c);
	else if (h == 4)
		ft_set_rgb(rgb, x, 0, c);
	else if (h == 5)
		ft_set_rgb(rgb, c, 0, x);
	return ((int)floor(rgb[0] * 255) << 16 | (int)floor(rgb[1] * 255) << 8
		| (int)floor(rgb[2] * 255));
}

void	ft_set_rgb(double *rgb, double a, double b, double c)
{
	rgb[0] = a;
	rgb[1] = b;
	rgb[2] = c;
	return ;
}

