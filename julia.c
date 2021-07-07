#include "fractol.h"


#define WIDTH 1000
#define HEIGHT 1000
int put_Julia(double  x, double y);

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int i;
    int j;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 600, "test");
    i = 0;
    while (i < 600)
    {
        j = 0;
        while (j < 600)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j,  put_Julia(((double)i - 300) / 150, (((double)j - 300) / 150)));
            j++;
        }
        i++;
    }
    mlx_loop(mlx_ptr);
}

int put_Julia(double  x, double y)
{
	int i;
	int max_iterations;
	t_complex z;
	double xtmp;
	t_complex c;

	i = 1;
	z.re = x;
	z.im = y;
	printf("z.re = %lf , z.im = %lf ", z.re, z.im);
	c.re = 0;
	c.im = 0;
	max_iterations = 100;
	while(i < max_iterations && z.re * z.re + z.im * z.im <= 4)
	{
		xtmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = xtmp;
		i++;
	}
	if (i == max_iterations)
		return (255);
	return (255 / i);
}
