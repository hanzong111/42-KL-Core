/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:06:37 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/06 17:29:42 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;
	char	*init_ptr;

	len = ft_strlen((char *)s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	init_ptr = str;
	while (*(char *)s1 != '\0')
	{
		*str = *(char *)s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (init_ptr);
}
