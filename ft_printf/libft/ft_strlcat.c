/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:23:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/05 10:50:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destcount;
	size_t	srccount;
	size_t	i;
	size_t	renlen;

	destcount = 0;
	srccount = 0;
	i = 0;
	while (dest[destcount] != '\0')
		destcount++;
	while (src[srccount] != '\0')
		srccount++;
	if (size <= destcount)
		return (srccount + size);
	else
		renlen = destcount + srccount;
	while (src[i] != '\0' && (destcount + 1) < size)
	{
		dest[destcount] = src[i];
		i++;
		destcount++;
	}
	dest[destcount] = '\0';
	return (renlen);
}
