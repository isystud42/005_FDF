/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gui_selection_screen_text.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:49:44 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:42:45 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_gui_selection_screen_text(t_fdf_env *env)
{
	int     start_x;
	int     start_y;

	start_x = WIDTH / 2;
	start_y = HEIGHT / 3 - 200;
	if (env->gui_global_state == 0)
	{
		STR(MLX, WIN, start_x - 96, start_y, 0xFFFFFF, "REPRESENTATION TYPE");
		STR(MLX, WIN, start_x - 43, start_y + 30, 0xFFFFFF, "PARALLEL");
		STR(MLX, WIN, start_x - 48, start_y + 60, 0xFFFFFF, "ISOMETRIC");
		STR(MLX, WIN, start_x - 53, start_y + 150, 0xFFFFFF, "COLOR TYPE");
		STR(MLX, WIN, start_x - 78, start_y + 180, 0xFFFFFF, "BLACK AND WHITE");
		STR(MLX, WIN, start_x - 58, start_y + 210, 0xFFFFFF, "FILE-PICKED");
		STR(MLX, WIN, start_x - 35, start_y + 240, 0xFFFFFF, "CUSTOM");
		STR(MLX, WIN, start_x - 35, HEIGHT - 500, 0xFFFFFF, "LAUNCH");
	}
	if (env->gui_global_state == 0 || env->gui_global_state == 1)
	{
		STR(MLX, WIN, WIDTH - 200, HEIGHT - 200, 0xFFFFFF, "RESET");
		STR(MLX, WIN, WIDTH - 200, HEIGHT - 170, 0xFFFFFF, "EXIT");
	}
}

