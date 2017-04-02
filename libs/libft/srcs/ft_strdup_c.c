/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:33:57 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/26 00:58:11 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strdup_c function returns an allocated with malloc '\0' terminating
** copy of the 's' string until the 'c' character is found, or NULL if the 'c'
** character is not found.
*/

#include "libft.h"

char	*ft_strdup_c(char *s, char c)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!(ft_strchr(s, c)))
		return (NULL);
	while (s[i] != c)
		i++;
	if (!(new_s = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != c)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
