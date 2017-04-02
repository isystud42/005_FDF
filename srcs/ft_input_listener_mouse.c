/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_listener_mouse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:10:36 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:42:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_input_listener_mouse(int button, int x, int y, void *param)
{
	t_fdf_env *env;

	env = (t_fdf_env*)param;
	(void)button;
	if (env->gui_global_state == 0)
	{
		if (x >= 1380 && x <= 1405)
			ft_handle_mouse_input_choices(env, y);
		if (x >= 1180 && x <= 1380 && y >= 800 & y <= 830)
			ft_handle_mouse_input_launch(env);
	}
	if (env->gui_global_state == 0 || env->gui_global_state == 1)
	{
		if (x >= 2285 && x <= 2485)
			ft_handle_mouse_input_reset_or_close(env, y);
	}
	return (0);
}
