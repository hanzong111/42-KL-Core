/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:55:27 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/06 20:34:26 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char			*str1;
	int				sign;
	long int		sum;

	sum = 0;
	sign = 1;
	str1 = (char *)str;
	while (*str1 == ' ' || *str1 == '\t' || *str1 == '\n' || *str1 == '\f'
		|| *str1 == '\r' || *str1 == '\v')
		str1++;
	if (*str1 == '-')
		sign = -1;
	if (*str1 == '-' || *str1 == '+')
		str1++;
	while (*str1 >= '0' && *str1 <= '9')
	{
		sum = sum * 10 + *str1 - '0';
		if ((sum * sign) > 2147483647)
			return (-1);
		if ((sum * sign) < -2147483648)
			return (0);
		str1++;
	}
	return (sum * sign);
}
