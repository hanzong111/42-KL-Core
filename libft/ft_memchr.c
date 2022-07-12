/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:25:14 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/05 18:11:01 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str != NULL && i < n)
	{
		if (*str == (char)c)
			return ((unsigned char *)str);
		str++;
		i++;
	}
	if (str == NULL && c == '\0')
	{
		if (*str == (char)c)
			return (NULL);
	}
	return (NULL);
}
