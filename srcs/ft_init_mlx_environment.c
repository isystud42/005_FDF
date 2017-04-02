/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_environment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 03:14:00 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 03:16:19 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_init_mlx_environment(t_fdf_env *env, char *path)
{
	if ((!(MLX = mlx_init())) ||
		(!(WIN = mlx_new_window(MLX, WIDTH, HEIGHT, TITLE)) ||
		(!(ft_convert_path_to_int_tables(env, path)))))
		return (0);
	return (1);
}
