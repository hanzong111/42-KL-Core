/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:49:34 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/05 17:00:07 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*final_ptr;
	int		counter;

	counter = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			final_ptr = str;
			counter++;
		}
		str++;
	}
	if (counter != 0)
		return (final_ptr);
	if (c == '\0')
		return (str);
	else
		return (NULL);
}
