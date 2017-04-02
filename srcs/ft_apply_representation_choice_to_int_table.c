/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_representation_choice_to_int_tab          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:28:21 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/13 21:36:11 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		**ft_apply_representation_choice_to_int_table(t_fdf_env *env)
{
	int		**ret;

	if (env->gui_representation_type == 1)//PARALLEL
		return (handle_parallel_representation_type(env));
	if (env->gui_representation_type == 2)//ISOMETRIC
		return (handle_isometric_representation_type(env));
	else//CONICAL
		return (handle_conical_representation_type(env));
}
