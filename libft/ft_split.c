/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:12:10 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/07 17:30:03 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sepcount(char *s, char c)
{
	int	i;
	int	arrycount;

	arrycount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && (i == 0 || s[i - 1] != c))
			arrycount++;
		i++;
	}
	if (s[i - 1] == c && s[0] == c)
		return (arrycount - 1);
	else if (s[i - 1] != c && s[0] != c)
		return (arrycount + 1);
	else
		return (arrycount);
}

char	*ft_strcopy(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_sepcount((char *)s, c) + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= (int)ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (int)ft_strlen((char *)s)) && index >= 0)
		{
			split[j++] = ft_strcopy((char *)s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
