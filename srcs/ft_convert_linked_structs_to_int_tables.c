/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_linked_structs_to_int_tables.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 06:02:23 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 03:34:31 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	put_zeros_into_remaining_space(t_fdf_env *env, int *i, int *j)
{
	while (*j < env->most_values_into_one_line)
	{
		VAL[*i][*j] = 0;
		CLR[*i][*j] = 0;
		*j += 1;
	}
}

static void	put_values_into_int_tabs(t_fdf_env *env, int *i, int *j, int *k)
{
	while (LINE[*k])
	{
		while (LINE[*k] == ' ')
			*k += 1;
		if (LINE[*k] && LINE[*k] >= '0' && LINE[*k] <= '9')
			VAL[*i][*j] = ft_atoi(&LINE[*k]);
		while (LINE[*k] && LINE[*k] != ',' && LINE[*k] != ' ')
			*k += 1;
		if (LINE[*k] && LINE[*k] == ',')
			CLR[*i][*j] = ft_atoi_base(&LINE[*k + 3], 16);
		else
			CLR[*i][*j] = 16777215; //11111111 11111111 11111111 0xFFFFFF
		while (LINE[*k] && LINE[*k] != ' ')
			*k += 1;
		*j += 1;
	}
}

int			ft_convert_linked_structs_to_int_tables(t_fdf_env *env)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	if ((!(VAL = (int**)malloc(sizeof(int**) * env->line_nb))) ||
		(!(CLR = (int**)malloc(sizeof(int**) * env->line_nb))))
		return (0);
	while (++i < env->line_nb)
	{
		if ((!(VAL[i] = (int*)malloc(sizeof(int) * SIZE))) ||
			(!(CLR[i] = (int*)malloc(sizeof(int) * SIZE))))
			return (0);
		put_values_into_int_tabs(env, &i, &j, &k);
		k = 0;
		put_zeros_into_remaining_space(env, &i, &j);
		j = 0;
		env->file = env->file->next;
	}
	return (1);
}
