#include "fractol.h"

void	ft_error(void)
{
    write(2, "ERROR\n", 6);
	write(2, "You can use this program like this\n", 35);
    write(2, "./fractol Mandelbrot\n", 21);
    write(2, "./fractol Julia <float> <float>\n", 32);
    write(2, "<float> have to write like this \"123.4567\"\n", 44);
    write(2, "Good Julia pattern\n./fractol Julia 0 1\n./fractol Julia 0.3 0.6\n", 65);
	exit (0);
}
