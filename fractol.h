#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdint.h>
# include <limits.h>

//for minilibx
# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "../minilibx-linux/mlx.h"

# define _RED "\x1b[31m"
# define _GRN "\x1b[32m"
# define _YLW "\x1b[33m"
# define _BLUE "\x1b[34m"
# define _MGT "\x1b[35m"
# define _CYAN "\x1b[36m"
# define _END "\x1b[39m"

# define _MANDELBR 0
# define _JULIA 1
# define K_ESC		65307

# define _WIDTH 600
# define _HEIGHT 600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_frac
{
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	zoom;
	int		type;
	void	*mlx_ptr;
	void	*win_ptr;
	struct s_data data;
}	t_frac;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_initialize(int argc, char **argv, t_frac *fraction);
void	ft_error(void);
void	ft_make_img(t_frac *frac);
void	ft_show(t_frac *frac);
//一旦実験用
int	ft_julia(double  x, double y, t_frac *frac);

int		ft_is_float(char *s);
int		ft_isspace(char c);
int		ft_atof(char *s, int i, double *result);
int		ft_atol(char *s, int i, double *result);
size_t	ft_strlen(char *s);

int		ft_isdigit(int c);
int		ft_isint(char *str);
long	*ft_myatoi(char *s, long *num);
int		ft_strcmp(const char *s1, const char *s2);


void	ft_use_mlx(t_frac *frac);
int		ft_key_event(int kyecode, t_frac *frac);
void	ft_close(t_frac *frac);
int		ft_click_event(int kyecode, t_frac *frac);
int		ft_mmove(int x, int y, t_frac *frac);
int		ft_mroll(int zoom, int x, int y, t_frac *frac);
#endif
