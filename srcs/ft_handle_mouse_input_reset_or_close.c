/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouse_input_reset_or_close.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:02:46 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 05:09:53 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_handle_mouse_input_reset_or_close(t_fdf_env *env, int y)
{
	if (y >= 1100 && y <= 1125)
	{
		mlx_clear_window(MLX, WIN);
		env->gui_global_state = 0;
		ft_draw_gui_selection_screen(env);
		env->gui_representation_type = 0;
		env->gui_color_choice = 0;
		X = 0;
		Y = 0;
		I = 0;
		J = 0;
	}
	else if (y >= 1130 && y <= 1160)
		exit(0);
}
