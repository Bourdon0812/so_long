/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:47:51 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/05 17:33:35 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putsign(const char c, int *sign)
{
	if (c != '+' && c != '-')
		return (0);
	if (c == '-')
		*sign = *sign + 1;
	return (1);
}

static int	ft_putresult(const char c, long *result)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	*result = *result * 10 + (c - 48);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 0;
	result = 0;
	while (ft_iswsp((int)str[i]))
		i++;
	if (ft_putsign(str[i], &sign))
		i++;
	while (ft_putresult(str[i], &result))
		i++;
	if (sign % 2 != 0)
		result = -result;
	return (result);
}
