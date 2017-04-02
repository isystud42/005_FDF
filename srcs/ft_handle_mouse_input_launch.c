/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouse_input_launch.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:49:15 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:45:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_handle_mouse_input_launch(t_fdf_env *env)
{
	if (env->gui_representation_type && env->gui_color_choice)
	{
		env->gui_global_state = 1;
		ft_get_global_values(env);
		mlx_clear_window(MLX, WIN);
		ft_draw_gui_selection_screen(env);
		ft_launch_fdf_computing(env);
	}
}
