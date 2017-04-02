/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouse_input_choices.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:48:53 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/13 21:31:22 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void handle_color_choices(t_fdf_env *env, int y)
{
	if (y > 415 && y < 440)//BLACK AND WHITE
	{
		STR(MLX, WIN, 1387, 414, 0xFFFFFF, "X");
	    env->gui_color_choice = 1;
	}
	else if (y > 445 && y < 470)//FILE-PICKED
	{
		STR(MLX, WIN, 1387, 444, 0xFFFFFF, "X");
	    env->gui_color_choice = 2;
	}
	else if (y > 475 && y < 500)//CUSTOM
	{
		STR(MLX, WIN, 1387, 474, 0xFFFFFF, "X");
	    env->gui_color_choice = 3;
	}
}

static void	handle_representation_choices(t_fdf_env *env, int y)
{
	if (y > 265 && y < 290)//PARALLEL
	{
		STR(MLX, WIN, 1387, 264, 0xFFFFFF, "X");
		env->gui_representation_type = 1;
	}
	else if (y > 295 && y < 320)//ISOMETRIC
	{
		STR(MLX, WIN, 1387, 294, 0xFFFFFF, "X");
		env->gui_representation_type = 2;
	}
}

static void erase_boxes_filling(t_fdf_env *env, int mod)
{
	int	start_x;
	int	start_y;
	int	format[] = {25, 25, 0x0};

	start_x = WIDTH / 2 + 100;
	start_y = HEIGHT / 3 - 200;
	if (mod == 0)
	{
		ft_draw_quad(env, start_x, start_y + 30, format);
		ft_draw_quad(env, start_x, start_y + 60, format);
		ft_draw_quad(env, start_x, start_y + 90, format);
	}
	else if (mod == 1)
	{
		ft_draw_quad(env, start_x, start_y + 180, format);
		ft_draw_quad(env, start_x, start_y + 210, format);
		ft_draw_quad(env, start_x, start_y + 240, format);
	}
}
void	ft_handle_mouse_input_choices(t_fdf_env *env, int y)
{
	if ((y > 265 && y < 290) || (y > 295 && y < 320) || (y > 325 && y < 350))
	{
		erase_boxes_filling(env, 0);
		ft_draw_boxes(env);
		handle_representation_choices(env, y);
	}
	if ((y > 415 && y < 440) || (y > 445 && y < 470) || (y > 475 && y < 500))
	{
		erase_boxes_filling(env, 1);
		ft_draw_boxes(env);
		handle_color_choices(env, y);
	}
}
