/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:09:16 by jlereffa          #+#    #+#             */
/*   Updated: 2016/12/28 17:38:05 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>

typedef struct s_file t_file;

struct		s_file//OK
{
	char	*line;
	t_file	*next;
};

typedef struct s_mlx t_mlx;

struct		s_mlx//OK
{
	int		x;//Possibly not used anymore
	int		y;//Possibly not used anymore
	int		z;//OK
	int		clr;//OK <- change name, shorter ?
	int		end;//OK
};

typedef struct	s_s_var t_s_var;

struct		s_s_var//OK
{
	char	*s;
	int		x;
	int		y;
	int		x_s;
	int		x_size;
	t_mlx	*s_s;
};

typedef struct s_var	t_var;

struct		s_var//To do again.
{
	
};

typedef struct s_env    t_env;

struct      s_env//New, better var form.
{
	void    *mlx;
	void    *win;
	int     representation_mod;
	int     color_mod;
	int		menu_id;
	t_mlx	**file;
	t_mlx	**pixel;
	t_var	*var;
};


typedef struct s_format	t_format;

struct		s_format//OK
{
	int		o_x;//OK
	int		o_y;//OK
	int		lenght;//OK
	int		width;//OK
};

void		ft_draw_pixel(t_env *env, int x, int y, int color);
char        **ft_convert_file_to_tab(char *path, int *passed_fd);
int			ft_draw_launch_menu(t_var *env);//<- To do
int			ft_input_listener_expose(void *param);//<- To do
int         ft_input_listener_keyboard(int keycode, void *param);
int         ft_input_listener_mouse(int button, int x, int y, void *param);//<-watch
int			ft_return_usage(void);
t_env		*ft_init_env(void);//<- got a function to delete.
t_mlx       **ft_convert_tab_to_struct(char **tab);
t_var		*ft_init_var(void);


void		ft_display_color_menu(t_var *var, int x, int y);
void		ft_draw_shape(void *mlx, void *win, t_format *form, int mod);//OK
void		ft_erase_menu(t_var *var, int col, int ref);//OK
void		ft_place_elipixel(t_var *var, int mod);
void		ft_place_launch_menu_texts(t_var *var, int x, int y);
void		ft_reset_launch_menu(t_var *var);
void		ft_get_steps_from_tab(t_mlx **tab, int *step_x, int *step_y);
int			ft_display_launch_menu_window(t_var *var, int x, int y);
int			ft_place_slider(t_var *var);
int			ft_handle_display(t_mlx **tab, t_mlx **pixel);//OK
int			ft_keyboard_input_listener(int keycode, void *var);//OK
int			ft_mouse_input_listener(int button, int x, int y, void *param);//
int			ft_start_graphical_representation(t_var *var);
t_format	*ft_init_t_format(int o_x, int o_y, int mod);//OK
t_var		*ft_launch_menu_window(t_mlx **tab, t_mlx **pixel);
t_var		*ft_init_t_var(t_mlx **tab, t_mlx **pixel, int mod);//OK
#endif
