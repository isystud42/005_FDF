/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:27:25 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 05:18:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_print_int_table(t_fdf_env *env, int **tab)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < env->line_nb)
	{
		while (++j < env->most_values_into_one_line)
			PXL(MLX, WIN,
				X + ORI_X + ((0.5 * j - 0.5 * i) * (STEP_X + ZOOM)),
				Y + ORI_Y + ((-tab[i][j] + 0.25 * j + 0.25 * i) * (STEP_Y + ZOOM)), 0xFF0000);
		j = -1;
	}
}
