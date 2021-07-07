#include "fractol.h"

#define WIDTH 1000
#define HEIGHT 1000

int put_Mandelbrot(double  x, double y, double scale);

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

int	main()
{
    void *mlx_ptr;
    void *win_ptr;
	void *img;
    int i;
    int j;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 600, "test");
    img = mlx_new_image(mlx_ptr, 600, 600);
	i = 0;
    while (i < 600)
    {
        j = 0;
        while (j < 600)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j,  put_Mandelbrot((double)i , (double)j, 400));
            j++;
        }
        i++;
    }
    mlx_loop(mlx_ptr);
}

int	put_Mandelbrot(double  x, double y, double scale)
{
	int i;
	int max_iterations;
	t_complex z;
	double xtmp;
	t_complex c;

	i = 0;
	z.re = 0;
	z.im = 0;
	c.re = (x - 0 - 0.7 * 600) / scale;
	c.im = (y  -0 - 0.5 * 600) / scale;
	max_iterations = 30;
	while(z.re * z.re + z.im * z.im < 10000000000 && i < max_iterations)
	{
		xtmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = xtmp;
		i++;
	}
	if (i == max_iterations)
		return (0);
	return ((255 + (255 << 8) + (255 << 16)) / i);
}

//zの大きさによっていい感じに色のコントラストを付けるような関数を用意するとうまく行きそう
// from PIL import Image, ImageDraw
// from mandelbrot import mandelbrot, MAX_ITER
// # Image size (pixels)
// WIDTH = 600
// HEIGHT = 400

// # Plot window
// RE_START = -2
// RE_END = 1
// IM_START = -1
// IM_END = 1

// palette = []

// im = Image.new('RGB', (WIDTH, HEIGHT), (0, 0, 0))
// draw = ImageDraw.Draw(im)

// for x in range(0, WIDTH):
//     for y in range(0, HEIGHT):
//         # Convert pixel coordinate to complex number
//         c = complex(RE_START + (x / WIDTH) * (RE_END - RE_START),
//                     IM_START + (y / HEIGHT) * (IM_END - IM_START))
//         # Compute the number of iterations
//         m = mandelbrot(c)
//         # The color depends on the number of iterations
//         color = 255 - int(m * 255 / MAX_ITER)
//         # Plot the point
//         draw.point([x, y], (color, color, color))

// im.save('output.png', 'PNG')
