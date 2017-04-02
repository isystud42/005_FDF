/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:16:58 by jlereffa          #+#    #+#             */
/*   Updated: 2016/12/08 16:57:49 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	handle_neg_base_ten(char *s, int base_from, int *is_neg, int *x)
{
	if (base_from == 10 && s[0] == '-')
	{
		*is_neg = 1;
		*x += 1;
	}
}

int			ft_atoi_base(char *s, int base_from)
{
	int		is_neg;
	int		x;
	long	ret;

	is_neg = 0;
	ret = 0;
	x = 0;
	handle_neg_base_ten(s, base_from, &is_neg, &x);
	while ((s[x] && s[x] >= '0' && s[x] <= '9') ||
			(s[x] && s[x] >= 'A' && s[x] <= 'Z'))
	{
		if (s[x] >= '0' && s[x] <= '9')
			ret = ret * base_from + (s[x] - '0');
		else
			ret = ret * base_from + (s[x] - 'A' + 10);
		x++;
	}
	if ((ret < -2147483648) || (ret > 2147483647 && is_neg == 0) ||
		ret > 2147483648)
		return (0);
	if (is_neg == 1 && ret > 0)
		return ((int)(ret *= -1));
	return (ret);
}
