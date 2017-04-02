/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 03:22:20 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 03:24:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			main(int argc, char **argv)
{
	t_fdf_env	env;;

	if (argc != 2 ||
		(!(ft_init_t_env(&env)))||
		(!(ft_init_mlx_environment(&env, argv[1]))))
		return (ft_error_return());
	ft_draw_gui_selection_screen(&env);
	mlx_key_hook(env.win, ft_input_listener_keyboard, &env);
	mlx_mouse_hook(env.win, ft_input_listener_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}
