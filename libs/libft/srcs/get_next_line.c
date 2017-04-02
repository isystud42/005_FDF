/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:12:22 by jlereffa          #+#    #+#             */
/*   Updated: 2016/12/16 21:34:29 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*ft_set_list_gnl(t_gnl *lst, int fd)
{
	if (!lst)
	{
		if (!(lst = (t_gnl*)malloc(sizeof(t_gnl))))
			return (NULL);
		lst->fd = fd;
		lst->ret = 0;
		lst->rest = NULL;
		lst->tmp = NULL;
		lst->prev = NULL;
		lst->next = NULL;
		return (lst);
	}
	while (lst->prev && lst->fd != fd)
		lst = lst->prev;
	while (lst->next && (lst->fd != fd))
		lst = lst->next;
	if (lst->fd != fd)
	{
		lst->next = ft_set_list_gnl(lst->next, fd);
		lst->next->prev = lst;
		return (lst->next);
	}
	return (lst);
}

static void		ft_remove_lst_fd(t_gnl **lst)
{
	t_gnl		*tmp;

	tmp = *lst;
	if ((*lst)->rest)
		free((*lst)->rest);
	if ((*lst)->prev && (*lst)->next)
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->prev;
	}
	else if ((*lst)->prev && !(*lst)->next)
	{
		(*lst)->prev->next = NULL;
		*lst = (*lst)->prev;
	}
	else if (!(*lst)->prev && (*lst)->next)
	{
		(*lst)->next->prev = NULL;
		*lst = (*lst)->next;
	}
	else
		*lst = NULL;
	free(tmp);
}

static int		ft_handle_rest(t_gnl *lst)
{
	lst->tmp = lst->rest;
	lst->rest = ft_strchr(lst->rest, '\n');
	if (lst->rest[1])
		lst->rest = ft_strdup(&lst->rest[1]);
	else
		lst->rest = NULL;
	ft_strdel(&lst->tmp);
	return (1);
}

static int		ft_handle_null_ret(char **line, t_gnl **lst)
{
	if ((*lst)->rest)
	{
		if ((*line = ft_strdup_c((*lst)->rest, '\n')))
			return (ft_handle_rest(*lst));
		else
		{
			*line = ft_strdup((*lst)->rest);
			(*lst)->rest = NULL;
			return (1);
		}
	}
	ft_remove_lst_fd(&*lst);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!(lst = ft_set_list_gnl(lst, fd)))
		return (-1);
	while ((lst->ret = read(lst->fd, lst->buf, BUFF_SIZE)) >= 0)
	{
		if (lst->ret > 0)
		{
			if (!(ft_strrealloc_more(&lst->rest, lst->ret)))
				return (-1);
			lst->rest = ft_strncat(lst->rest, lst->buf, lst->ret);
			if ((*line = ft_strdup_c(lst->rest, '\n')))
				return (ft_handle_rest(lst));
		}
		else
			return (ft_handle_null_ret(&*line, &lst));
	}
	return (-1);
}
