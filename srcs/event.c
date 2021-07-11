#include "fractol.h"

void	ft_use_mlx(t_frac *frac)
{
	ft_show(frac);
	mlx_hook(frac->win_ptr, 2, 1L << 0, ft_key_event, frac);
	mlx_mouse_hook(frac->win_ptr, ft_mroll, frac);
	mlx_hook(frac->win_ptr, 33, 1L << 17, ft_click_event, frac);
	mlx_loop(frac->mlx_ptr);
}

int	ft_click_event(t_frac *frac)
{
	ft_close(frac);
	return (0);
}

int	ft_key_event(int keycode, t_frac *frac)
{
	if (keycode == K_ESC)
		ft_close(frac);
	else if (keycode == K_RIGHT)
	{
		frac->c_x = frac->c_x - 5;
		ft_show(frac);
	}
	else if (keycode == K_LEFT)
	{
		frac->c_x = frac->c_x + 5;
		ft_show(frac);
	}
	else if (keycode == K_UP)
	{
		frac->c_y = frac->c_y + 5;
		ft_show(frac);
	}
	else if (keycode == K_DOWN)
	{
		frac->c_y = frac->c_y - 5;
		ft_show(frac);
	}
	return (0);
}

int	ft_mroll(int keycode, int x, int y, t_frac *frac)
{
	(void)x;
	(void)y;
	if (keycode == UP)
	{
		frac->zoom = frac->zoom * 1.05;
		ft_show(frac);
	}
	else if (keycode == DOWN)
	{
		frac->zoom = frac->zoom / 1.05;
		ft_show(frac);
	}
	return (0);
}

// frac->c_x = frac->c_x + _WIDTH / 2 - x;
// frac->c_y = frac->c_y - _HEIGHT / 2 + y;

void	ft_close(t_frac *frac)
{
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	exit (0);
	return ;
}
