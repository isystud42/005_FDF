/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:54:18 by jlereffa          #+#    #+#             */
/*   Updated: 2016/12/07 17:13:24 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_base_size(long value, long base)
{
	int		ret;

	ret = 0;
	while (value > 0)
	{
		value /= base;
		ret++;
	}
	return (ret);
}

static char	*ft_itoa_base_long(long value, long base)
{
	char	*s;
	int		is_neg;
	int		size;

	is_neg = 0;
	if (base == 10 && value < 0)
		is_neg = 1;
	if (value < 0)
		value *= -1;
	size = ft_get_base_size(value, base);
	if (!(s = (char*)malloc(sizeof(char) * size + is_neg + 1)))
		return (NULL);
	s[size + is_neg] = '\0';
	while (size)
	{
		if (value % base < 10)
			s[size + is_neg - 1] = value % base + '0';
		else
			s[size + is_neg - 1] = value % base + 'A' - 10;
		value /= base;
		size--;
	}
	if (is_neg == 1)
		s[0] = '-';
	return (s);
}

char		*ft_itoa_base(int value, int base)
{
	char	*s;

	if (value == 0)
	{
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	return (ft_itoa_base_long(value, base));
}
