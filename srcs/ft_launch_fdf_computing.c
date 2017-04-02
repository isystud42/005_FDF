/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_fdf_computing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:16:46 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_launch_fdf_computing(t_fdf_env *env)
{
	ft_bigtab_filling(env,env->values);
	ft_trace_links(env);
	if (COLOR_MODE == 1)
		ft_print_bigtab_vanilla(env);
	if (COLOR_MODE == 2)
		ft_print_bigtab(env);
	if (COLOR_MODE == 3)
		ft_print_bigtab(env);
}
