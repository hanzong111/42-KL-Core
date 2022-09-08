/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:11:35 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/07 17:31:38 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		index;
	char	*init_ptr;

	index = (int)start;
	if (!s)
		return (NULL);
	if (index > (int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen(index + (char *)s))
		len = ft_strlen(index + (char *)s);
	substr = (char *)malloc(sizeof(char) * (int)len + 1);
	if (substr == NULL)
		return (NULL);
	init_ptr = substr;
	while (len > 0)
	{
		*substr = s[index];
		substr++;
		index++;
		len--;
	}
	*substr = '\0';
	return (init_ptr);
}
