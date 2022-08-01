/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:15:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/07 12:17:10 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcompare(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1);
	while (ft_strcompare(s1[start], set))
		start++;
	while (start <= end && ft_strcompare(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = (char)s1[start++];
	str[i] = '\0';
	return (str);
}
