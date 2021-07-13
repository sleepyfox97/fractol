#include "fractol.h"

int	ft_hsv_to_rgb(double h, double s, double v)
{
	double	x;
	double	c;
	double	rgb[3];

	c = v * s;
	h = h / 60;
	if ((int)floor(h) % 2 == 1)
		x = c * (1 - fabs(h - floor(h)));
	else
		x = c * (1 - fabs(h - floor(h) - 1));
	if (0 <= h && h < 1)
		ft_set_rgb(rgb, c, x, 0);
	else if (1 <= h && h < 2)
		ft_set_rgb(rgb, x, c, 0);
	else if (2 <= h && h < 3)
		ft_set_rgb(rgb, 0, c, x);
	else if (3 <= h && h < 4)
		ft_set_rgb(rgb, 0, x, c);
	else if (4 <= h && h < 5)
		ft_set_rgb(rgb, x, 0, c);
	else if (5 <= h && h < 6)
		ft_set_rgb(rgb, c, 0, x);
	ft_set_rgb(rgb, rgb[0] + (v - c), rgb[1] + (v - c), rgb[2] + (v - c));
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

// #include <stdlib.h>
// int		main(int argc, char *argv[])
// {
// 	double hsv[3];

// 	if (argc != 4)
// 		return (0);
// 	hsv[0] = atof(argv[1]);
// 	hsv[1] = atof(argv[2]);
// 	hsv[2] = atof(argv[3]);
// 	printf("%.6x\n",ft_hsv_to_rgv(hsv[0], hsv[1], hsv[2]));
// 	return (0);
// }
