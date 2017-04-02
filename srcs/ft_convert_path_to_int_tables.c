/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_path_to_int_tables.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 03:55:50 by jlereffa          #+#    #+#             */
/*   Updated: 2017/03/15 04:01:26 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_fdf_file	*set_t_fdf_file(t_fdf_file *file)
{
	t_fdf_file	*tmp;

	if (!file)
	{
		if (!(file = (t_fdf_file*)malloc(sizeof(t_fdf_file))))
			return (NULL);
		file->line = NULL;
		file->next = NULL;
		file->prev = NULL;
	}
	else
	{
		tmp = file;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = set_t_fdf_file(tmp->next);
		tmp->next->prev = tmp;
	}
	return (file);
}

static t_fdf_file	*convert_path_to_linked_structs(int fd, int *line_count)
{
	int			first_turn;
	int			ret;
	t_fdf_file	*file;

	first_turn = 1;
	ret = 1;
	file = NULL;
	if (!(file = set_t_fdf_file(file)))
		return (NULL);
	while ((ret = get_next_line(fd, &file->line)) > 0)
	{
		set_t_fdf_file(file);
		file = file->next;
		*line_count += 1;
	}
	if (ret == -1)
		return (NULL);
	file = file->prev;
	free(file->next);
	file->next = NULL;
	while (file->prev)
		file = file->prev;
	return (file);
}

static int			get_longest_line(int *longest_line, t_fdf_file *file)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (file)
	{
		while (file->line[i])
		{
			while (file->line[i] == ' ')
				i++;
			if (file->line[i] && file->line[i] >= '0' && file->line[i] <= '9')
				tmp++;
			while (file->line[i] && file->line[i] != ' ')
				i++;
		}
		*longest_line = tmp > *longest_line ? tmp : *longest_line;
		tmp = 0;
		i = 0;
		file = file->next;
	}
	return (1);
}

static void			free_t_fdf_file(t_fdf_file *file)
{
	while (file)
	{
		if (file->next)
		{
			file = file->next;
			free(file->prev);
			file->prev = NULL;
		}
		else
		{
			free(file);
			file = NULL;
		}
	}
}

int					ft_convert_path_to_int_tables(t_fdf_env *env, char *path)
{
	int			fd;
	t_fdf_file	*tmp;

	if (((fd = open(path, O_RDONLY)) < 0) ||
		(!(env->file = convert_path_to_linked_structs(fd, &env->line_nb))))
		return (0);
	tmp = env->file;
	if ((!(get_longest_line(&env->most_values_into_one_line, env->file))) ||
		(!(ft_convert_linked_structs_to_int_tables(env))))
		return (0);
	free_t_fdf_file(tmp);
	BIG_TAB = ft_malloc_triple_int_tab(env->line_nb,SIZE);
	return (1);
}
