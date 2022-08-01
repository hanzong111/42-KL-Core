/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:55:53 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/05 11:20:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		srclength;
	char		*s;

	s = (char *)src;
	srclength = 0;
	i = 0;
	while (s[srclength] != '\0')
		srclength++;
	if (size <= 0)
		return (srclength);
	while (i < srclength && s[i] != '\0' && i < (size - 1))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (srclength);
}
