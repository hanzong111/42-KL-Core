/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:38:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/07 14:41:33 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitcount(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = 2;
		n = 147483648;
	}
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	while (n > 0 || (n == 0 && count == 0))
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_offset(char *str, int n)
{
	int	offset;

	offset = 0;
	if (n == -2147483648)
	{
		str[1] = '2';
		offset++;
	}
	if (n < 0)
	{
		str[0] = '-';
		offset++;
	}
	return (offset);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		dummy;
	int		offset;

	count = ft_digitcount(n);
	str = malloc (sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	offset = ft_offset(str, n);
	if (n == -2147483648)
		n = 147483648;
	if (n < 0)
		n = -n;
	dummy = 0;
	while (--count >= offset)
	{
		dummy = n % 10;
		n = n / 10;
		str[count] = dummy + '0';
	}
	return (str);
}
