#include "fractol.h"

void	ft_error(void)
{
	printf(_RED"%10s"_END"\n", "ERROR");
	printf("You can use this program like this\n");
	printf(_YLW"./fractol Mandelbrot\n");
	printf("./fractol Julia <float> <float>\n"_END);
	printf("<float> have to write like this \"123.4567\"\n");
	exit (0);
}
