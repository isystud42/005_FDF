/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 03:44:57 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 05:16:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_init_t_env(t_fdf_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->line_nb = 0;
	env->most_values_into_one_line = 0;
	env->gui_global_state = 0;
	env->gui_representation_type = 0;
	env->gui_color_choice = 0;
	env->gui_global_step_x = 0;
	env->gui_global_step_y = 0;
	env->gui_x_origin = 0;
	env->gui_y_origin = 0;
	env->x_mod = 0;
	env->y_mod = 0;
	env->zoom = 0;
	env->values = NULL;
	env->colors = NULL;
	env->file = NULL;
	env->bigtab = NULL;
	env->i = -1;
	env->j = -1;
	return (1);
}
