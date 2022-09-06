/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:39:11 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:41 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	To Count string length of str1 & str2 to get the malloc length	*/
/*	word count of str1 is stored in info->wc1						*/
/*	Word count of str2 is stored in info->wc2						*/
void	gnl_strlen(char *str1, char *str2, t_gnl *info)
{
	int	readwc;

	readwc = info->readwc;
	info->wc1 = 0;
	info->wc2 = 0;
	if (str1)
	{
		while (*str1 != '\0')
		{
			info->wc1++;
			str1++;
		}
	}
	while (--readwc >= 0)
	{
		if (*str2 == '\n')
		{
			info->wc2++;
			return ;
		}
		info->wc2++;
		str2++;
	}
	return ;
}

/* Type 1 is Partial copy */
/* Type 2 is Whole copy   */
void	gnl_strcopy(char *buffer, char *newstr, int len, int type)
{
	while (*buffer != '\0' && --len >= 0)
	{
		if (type == 1)
		{	
			if (*buffer == '\n')
			{
				*newstr = '\n';
				return ;
			}
		}
		*newstr = *buffer;
		newstr++;
		buffer++;
	}
}

/*	To make a complete duplicate of a string	*/
char	*gnl_strdup(char *newstr, int type)
{
	int		i;
	int		wc;
	char	*finalstr;

	wc = 0;
	i = -1;
	if (newstr == NULL || *newstr == '\0')
		return (NULL);
	while (newstr[++i] != '\0')
		wc++;
	finalstr = malloc(sizeof(char) * (wc + 1));
	finalstr[wc] = '\0';
	gnl_strcopy(newstr, finalstr, wc, type);
	return (finalstr);
}

/*	To join str1 & str2 together , to form a finalstr	*/
void	gnl_strjoin(char *buffer, t_gnl *info)
{
	char	*firststr;
	char	*newstr;
	char	*init_ptr;

	gnl_strlen(info->finalstr, buffer, info);
	if (info->wc1 == 0)
	{
		firststr = malloc(sizeof(char) * (info->wc2 + 1));
		firststr[info->wc2] = '\0';
		gnl_strcopy(buffer, firststr, info->wc2, 1);
		info->finalstr = firststr;
		return ;
	}
	newstr = malloc(sizeof(char) * (info->wc1 + info->wc2 + 1));
	newstr[info->wc1 + info->wc2] = '\0';
	init_ptr = info->finalstr;
	gnl_strcopy(info->finalstr, newstr, info->wc1, 1);
	gnl_strcopy(buffer, &newstr[info->wc1], info->wc2, 1);
	free(init_ptr);
	info->finalstr = gnl_strdup(newstr, 2);
	free(newstr);
}

/*	To read a line in a file , and generate a copy of that line	*/
/*	Storing the final produced string inside of info->finalstr	*/
char	*gnl_finalstr(int fd, char *buffer, t_gnl *info)
{
	info->readwc = read(fd, buffer, BUFFER_SIZE);
	while (info->readwc > 0)
	{
		if (gnl_checks(buffer))
		{
			gnl_strjoin(buffer, info);
			return (info->finalstr);
		}
		gnl_strjoin(buffer, info);
		info->readwc = read(fd, buffer, BUFFER_SIZE);
	}
	return (info->finalstr);
}
