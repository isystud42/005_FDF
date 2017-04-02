/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:05:56 by jlereffa          #+#    #+#             */
/*   Updated: 2017/01/14 05:55:46 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		trace_l_to_r(int *tab, int y2, int x2, t_env *env)
{
	int x;
	int	x1;
	int	y1;

	x1 = tab[1];
	y1 = tab[0];
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
		return (0);
	x = x1 + 1;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx, env->win, y1 + ((y2 - y1) *
			(x - x1)) / (x2 - x1), x, 0xFFFFFF);
		x++;
	}
	return (0);
}

int		trace_r_to_l(int *tab, int x2, int y2, t_env *env)
{
	int x;
	int	x1;
	int y1;

	x1 = tab[0];
	y1 = tab[1];
	while (x1 == x2 && y1 != y2)
	{
		mlx_pixel_put(env->mlx, env->win, x1, y1, 0xFFFFFF);
		y1++;
	}
	while (x1 != x2 && y1 == y2)
	{
		mlx_pixel_put(env->mlx, env->win, x1, y1, 0xFFFFFF);
		x1++;
	}
	x = x1;
	while (x < x2)
	{
		mlx_pixel_put(env->mlx, env->win, x, y1 + ((y2 - y1) *
			(x - x1)) / (x2 - x1), 0xFFFFFF);
		x++;
	}
	return (0);
}

void	ft_trace_lines(t_env *env)
{
	int			i;
	int			j;
	int			tab[2];

	file = env->file;
	i = 0;
	j = i;
	while (file[j])
	{
		while (!file[j][i].end)
		{
			tab[0] = file[j][i].x;
			tab[1] = file[j][i].y;
			if ((!file[j][i + 1].end) || (!file[j][i + 1].end && !file[j + 1]))
			{
				trace_l_to_r(tab, file[j][i + 1].x, file[j][i + 1].y, env);
				trace_r_to_l(tab, file[j][i + 1].x, file[j][i + 1].y, env);
			}
			if ((file[j + 1]) || (file[j + 1] && file[j][i + 1].end))
			{
				trace_r_to_l(tab, file[j + 1][i].x, file[j + 1][i].y, env);
				trace_l_to_r(tab, file[j + 1][i].x, file[j + 1][i].y, env);
			}
			i++;
		}
		i = 0;
		j++;
	}
}
