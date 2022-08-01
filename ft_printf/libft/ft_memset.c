/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:49:42 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/04 18:55:26 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	void	*init_ptr;
	size_t	i;

	i = 0;
	init_ptr = str;
	while (i < n)
	{
		*(char *)str = c;
		str++;
		i++;
	}
	return (init_ptr);
}
