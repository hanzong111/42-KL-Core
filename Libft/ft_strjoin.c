/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:37:41 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/07 12:14:39 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *str, char *dest);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*final_str;
	char	*init_ptr;
	int		totallength;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	totallength = ft_strlen(str1) + ft_strlen(str2);
	final_str = malloc(sizeof(char) * totallength + 1);
	if (final_str == NULL)
		return (NULL);
	init_ptr = final_str;
	final_str = ft_strjoin2(str1, final_str);
	final_str = ft_strjoin2(str2, final_str);
	*final_str = '\0';
	return (init_ptr);
}

char	*ft_strjoin2(char *str, char *dest)
{
	while (*str != '\0')
	{
		*dest = *str;
		str++;
		dest++;
	}
	return (dest);
}
