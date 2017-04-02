/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:09:16 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 05:16:36 by jlereffa         ###   ########.fr       */
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


# define I env->i
# define J env->j
# define X1 env->bigtab[env->i][env->j][0]
# define Y1 env->bigtab[env->i][env->j][1]
# define X2 xytab[0]
# define Y2 xytab[1]
# define VAL env->values
# define CLR env->colors
# define LINE env->file->line
# define MLX env->mlx
# define WIN env->win
# define WIDTH 2560
# define HEIGHT 1300
# define TITLE "FdF - GUI"
# define PXL mlx_pixel_put
# define STR mlx_string_put
# define STEP_X env->gui_global_step_x
# define STEP_Y env->gui_global_step_y
# define ORI_X env->gui_x_origin
# define ORI_Y env->gui_y_origin
# define SIZE env->most_values_into_one_line
# define X env->x_mod
# define Y env->y_mod
# define ZOOM env->zoom
# define VIEW_MODE env->gui_representation_type
# define BIG_TAB env->bigtab
# define COLOR_MODE env->gui_color_choice

typedef struct s_fdf_file	t_fdf_file;
struct			s_fdf_file
{
	char		*line;
	t_fdf_file	*next;
	t_fdf_file	*prev;
};

typedef struct s_fdf_env	t_fdf_env;
struct			s_fdf_env
{
	void		*mlx;
	void		*win;
	int			line_nb;
	int			most_values_into_one_line;
	int			gui_global_state;
	int			gui_representation_type;
	int			gui_color_choice;
	int			gui_global_step_x;
	int			gui_global_step_y;
	int			gui_x_origin;
	int			gui_y_origin;
	int			x_mod;
	int			y_mod;
	int			zoom;
	int			**values;
	int			**colors;
	int			***bigtab;
	int			i;
	int			j;
	t_fdf_file	*file;
};


int				***ft_malloc_triple_int_tab(int tabsize_1,int tabsize_2);

void			ft_bigtab_filling(t_fdf_env *env, int **values);
void    		ft_print_bigtab(t_fdf_env *env);
void    		ft_print_bigtab_vanilla(t_fdf_env *env);

void			ft_trace_links(t_fdf_env *env);
int				ft_handle_pixel_color(int clrxy, int clrxy1, int progress);

int				ft_init_mlx_environment(t_fdf_env *env, char *path);

void			ft_draw_gui_selection_screen(t_fdf_env *env);
void			ft_draw_gui_selection_screen_original_text_background(
				t_fdf_env *env);
void			ft_draw_gui_selection_screen_text(t_fdf_env *env);
void			ft_draw_quad(t_fdf_env *env, int x, int y, int *format);
void			ft_draw_boxes(t_fdf_env *env);

void			ft_handle_mouse_input_choices(t_fdf_env *env, int y);
void			ft_handle_mouse_input_reset_or_close(t_fdf_env *env, int y);
void			ft_handle_mouse_input_launch(t_fdf_env *env);

void			ft_get_global_values(t_fdf_env *env);
void			ft_launch_fdf_computing(t_fdf_env *env);
void			ft_print_int_table(t_fdf_env *env, int **tab);
int				**ft_apply_representation_choice_to_int_table(t_fdf_env *env);

int				ft_error_return(void);

int				ft_init_t_env(t_fdf_env *env);
int				ft_convert_path_to_int_tables(t_fdf_env *env, char *path);
int				ft_convert_linked_structs_to_int_tables(t_fdf_env *env);

int				ft_input_listener_keyboard(int keycode, void *param);
int				ft_input_listener_mouse(int button, int x, int y, void *param);
#endif
