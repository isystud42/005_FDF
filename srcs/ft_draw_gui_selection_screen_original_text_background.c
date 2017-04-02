/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gui_selection_screen_original_tex          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:23:32 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:43:11 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_gui_selection_screen_original_text_background(t_fdf_env *env)
{
	int		start_x;
	int		start_y;
	int		format[] = {200, 25, 0x415D76};

	start_x = WIDTH / 2 - 200 / 2;
	start_y = HEIGHT / 3 - 200;
	if (env->gui_global_state == 0)
	{
		ft_draw_quad(env, start_x, start_y, format);
		ft_draw_quad(env, start_x, start_y + 150, format);
		ft_draw_quad(env, start_x, HEIGHT - 500, format);
		ft_draw_quad(env, WIDTH - 275, HEIGHT - 200, format);
	}
	if (env->gui_global_state == 0 || env->gui_global_state == 1)
	{
		ft_draw_quad(env, WIDTH - 275, HEIGHT - 200, format);
		format[2] = 0xFE2A1D;
		ft_draw_quad(env, WIDTH - 275, HEIGHT - 170, format);
	}
}
