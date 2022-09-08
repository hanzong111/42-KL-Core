/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:34:15 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/05 16:45:54 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*source;
	char		*dest;

	if (dst == NULL && src == NULL)
		return (dst);
	dest = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		*dest = *source;
		dest++;
		source++;
		i++;
	}
	return (dst);
}
