/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_global_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:35:28 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 03:23:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_get_global_values(t_fdf_env *env)
{
	env->gui_global_step_x =
		(WIDTH / 2) / SIZE;
	env->gui_global_step_y =
		(HEIGHT / 2) / SIZE;
	env->gui_x_origin =
		(WIDTH / 2) - (SIZE * STEP_X) / 2;
	env->gui_y_origin =
		(HEIGHT / 2) - (env->line_nb * STEP_Y) / 2;
	printf("env->gui_global_step_x = %d\n", STEP_X);
	printf("env->gui_global_step_y = %d\n", STEP_Y);
	printf("env->gui_x_origin = %d\n", ORI_X);
	printf("env->gui_y_origin = %d\n", ORI_Y);
}
