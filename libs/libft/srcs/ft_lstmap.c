/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:29:54 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/27 19:49:49 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*tmp;
	t_list		*ret;

	new_lst = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new_lst)
		{
			new_lst = ft_lstnew(tmp->content, tmp->content_size);
			ret = new_lst;
		}
		else
		{
			new_lst->next = ft_lstnew(tmp->content, tmp->content_size);
			new_lst = new_lst->next;
		}
		lst = lst->next;
	}
	return (ret);
}
