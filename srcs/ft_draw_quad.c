/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:40:33 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/13 16:17:41 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_quad(t_fdf_env *env, int x, int y, int *format)
{
	int		x_origin;
	int		y_origin;

	x_origin = x;
	y_origin = y;
	while (y < y_origin + format[1])
	{
		while (x < x_origin + format[0])
		{
			PXL(MLX, WIN, x, y, format[2]);
			x++;
		}
		x = x_origin;
		y++;
	}
}
