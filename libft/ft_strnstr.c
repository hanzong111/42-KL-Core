/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:05:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/06 16:29:30 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compare(char *str, char *to_find, size_t i, size_t len);

char	*ft_strnstr(const char *s, const char *to, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	i;

	str = (char *)s;
	to_find = (char *)to;
	i = 0;
	if (*to_find == '\0' || to_find == NULL)
		return (str);
	while (*str != '\0' && i < len)
	{
		if (ft_compare(str, to_find, i, len))
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

int	ft_compare(char *str, char *to_find, size_t i, size_t len)
{
	while (*to_find == *str && i < len)
	{
		if (*(to_find + 1) == '\0')
			return (1);
		i++;
		str++;
		to_find++;
	}
	return (0);
}
