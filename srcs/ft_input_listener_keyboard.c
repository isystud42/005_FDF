/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_listener_keyboard.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:17:47 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 05:35:24 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	handle_x_y_translation(t_fdf_env *env, int keycode)
{
	mlx_clear_window(MLX, WIN);
	if (keycode == 88)
		X += 25;
	else if (keycode == 86)
		X -= 25;
	else if (keycode == 84)
		Y += 25;
	else
		Y -= 25;
	I = 0;
	J = 0;
	ft_launch_fdf_computing(env);
	ft_draw_gui_selection_screen(env);
}

static void	handle_zoom(t_fdf_env *env, int keycode)
{
	mlx_clear_window(MLX, WIN);
	if (keycode == 69)
		ZOOM += 100;
	else
	{
		if (env->gui_global_step_x * (100+ZOOM)/100 > 0 &&
			env->gui_global_step_y * (100+ZOOM)/100 > 0)
			ZOOM -= 100;
	}
	I = 0;
	J = 0;
	ft_launch_fdf_computing(env);
	ft_draw_gui_selection_screen(env);
}

void	handle_reset(t_fdf_env *env)
{
	mlx_clear_window(MLX, WIN);
	X = 0;
	Y = 0;
	ZOOM = 0;
	ft_launch_fdf_computing(env);
	ft_draw_gui_selection_screen(env);
}

int		ft_input_listener_keyboard(int keycode, void *param)
{
	t_fdf_env *env;

	env = (t_fdf_env*)param;
	if (keycode == 53)
		exit(0);
	if (env->gui_global_state == 1)
	{
		if (keycode == 88/*68*/ || keycode == 86/*4*/ || keycode == 91/*8*/ ||
		keycode == 84/*2*/)
			handle_x_y_translation(env, keycode);
		if (keycode == 78/*-*/ || keycode == 69/*+*/)
			handle_zoom(env, keycode);
		if (keycode == 71/*0*/)
			handle_reset(env);
	}
	return (0);
}
