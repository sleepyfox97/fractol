#include "fractol.h"


// #define WIDTH 1000
// #define HEIGHT 1000
// int put_Julia(double  x, double y);

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

// int main()
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     int i;
//     int j;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 600, 600, "test");
//     i = 0;
//     while (i < 600)
//     {
//         j = 0;
//         while (j < 600)
//         {
//             mlx_pixel_put(mlx_ptr, win_ptr, i, j,  put_Julia((double)i, (double)(600 - j)));
//             j++;
//         }
//         i++;
//     }
//     mlx_loop(mlx_ptr);
// }

// // int put_Julia(double  x, double y)
// // {
// // 	int i;
// // 	int max_iterations;
// // 	t_complex z;
// // 	double xtmp;
// // 	t_complex c;

// // 	i = 1;
// // 	z.re = (x - 300) / 150;
// // 	z.im = (y - 300) / 150;
// // 	// c.re = 0.28500;
// // 	// c.im = 0.00000;
// // 	// c.re = 0.28500;
// // 	// c.im = 0.01000;
// // 	c.re = -0.70176;
// // 	c.im = 0.3842;
// // 	max_iterations = 100;
// // 	while(i < max_iterations && z.re * z.re + z.im * z.im <= 4)
// // 	{
// // 		xtmp = z.re * z.re - z.im * z.im + c.re;
// // 		z.im = 2 * z.re * z.im + c.im;
// // 		z.re = xtmp;
// // 		i++;
// // 	}
// // 	if (i == max_iterations)
// // 		return (0);
// // 	return ((int)(255 / i) << 16 | (int)(255 / i) << 8 | (int)(255 / i));
// // }

int put_Julia(double  x, double y)
{
	int i;
	int max_iterations;
	t_complex z;
	double xtmp;
	t_complex c;

	i = 1;
	z.re = (x - 300) / 200; //( x - (中心)) / 倍率
	z.im = (y - 300) / 200;
	// c.re = 0.28500;
	// c.im = 0.00000;
	// c.re = 0.28500;
	// c.im = 0.01000;
	//c.re = -0.70176;
	//c.im = 0.3842;
	c.re = -0.8;
	c.im = 0.156; //上から下に書くから，虚軸は逆向き
	max_iterations = 255;
	while(i < max_iterations && z.re * z.re + z.im * z.im <= 4)
	{
		xtmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = xtmp;
		i++;
	}
	if (i == max_iterations)
		return (0);
	return (i << 16 | i << 8 | i);
}

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 600)
		{
			my_mlx_pixel_put(&img, x, 600 - y, put_Julia((double)x, (double)y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}