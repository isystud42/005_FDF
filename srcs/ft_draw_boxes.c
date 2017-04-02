/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_boxes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:08:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/13 16:21:12 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	draw(t_fdf_env *env, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 25)
	{
		while (j < 25)
		{
			if (i == 0 || j == 0 || i == 24 || j == 24)
				PXL(MLX, WIN, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_draw_boxes(t_fdf_env *env)
{
	int     start_x;
	int     start_y;

	start_x = WIDTH / 2 + 100;
	start_y = HEIGHT / 3 - 200;
	draw(env, start_x, start_y + 30);
	draw(env, start_x, start_y + 60);
	draw(env, start_x, start_y + 180);
	draw(env, start_x, start_y + 210);
	draw(env, start_x, start_y + 240);
}
