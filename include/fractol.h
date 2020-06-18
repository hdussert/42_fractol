
#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/include/libft.h"

typedef struct		s_fractale
{
	long double		min;
	long double		max;
	long double		t_a;
	long double		t_b;
	long double		ca;
	long double		cb;
	long double		scale;
	int				n_max;
	int				abs_max;
	int				mouse1;
}					t_fractale;

typedef struct		s_draw_params
{
	long double		a;
	long double		b;
	long double		sqr_a;
	long double		sqr_b;
	long double		fa;
	long double		fb;
	int				x;
	int				y;
	int				n;
	int				color;
}					t_draw_params;

typedef struct		s_image
{
	void		*ptr;
	char		*img;
	int			bpp;
	int			s_l;
	int			endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	int				size;
	double			size_2;
	t_image			*image;
	t_fractale		p;
	int				nfrac;
	int				num_max;
	int				time;
}					t_mlx;


long double			square(long double x);
long double			map(long double v, long double v_e,
						long double r_s, long double r_e);
int					calc_color(long double n);

void				usage(void);
void				draw(t_mlx *mlx);
void				reset_p(t_mlx *mlx);
int					key_down(int key, t_mlx *mlx);
int					mouse_down(int key, int x, int y, t_mlx *mlx);
int					mouse_up(int key, int x, int y, t_mlx *mlx);
int					mouse_motion(int x, int y, t_mlx *mlx);
int					loop(t_mlx *mlx);
void				draw_julia(t_mlx *mlx);
void				draw_mandelbrot(t_mlx *mlx);
void				draw_burningship(t_mlx *mlx);
void				draw_tricorn(t_mlx *mlx);
void				draw(t_mlx *mlx);
#endif
