/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gui_selection_screen.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:16:54 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 02:46:43 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_gui_selection_screen(t_fdf_env *env)
{
	ft_draw_gui_selection_screen_original_text_background(env);
	ft_draw_gui_selection_screen_text(env);
	if (env->gui_global_state == 0)
		ft_draw_boxes(env);
}
