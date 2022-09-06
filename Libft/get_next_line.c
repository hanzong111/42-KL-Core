/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:40 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	To Check if there is a '\n' in a string */
int	gnl_checks(char *buffer)
{
	if (buffer != NULL)
	{
		while (*buffer != '\0')
		{
			if (*buffer == '\n')
				return (1);
			else
				buffer++;
		}
	}
	return (0);
}

/*	To save remainder string behind the '\n' in the buffer */
char	*gnl_strsort(char *buffer, t_gnl *info)
{
	char	*nextstr;
	int		readwc;

	info->wc = 0;
	info->index = 0;
	readwc = info->readwc;
	while (*buffer != '\n' && --readwc >= 0)
		buffer++;
	if (info->readwc == 0 && !info->finalstr)
	{
		free(info->finalstr);
		info->finalstr = NULL;
		return (NULL);
	}
	else
	{
		buffer++;
		readwc--;
		while (buffer[info->index++] != '\0' && --readwc >= 0)
			info->wc++;
		nextstr = malloc(sizeof(char) * (info->wc + 1));
		nextstr[info->wc] = '\0';
		gnl_strcopy(buffer, nextstr, info->wc, 2);
		return (nextstr);
	}
}

/*	To Extract "finalstring" from "arry[fd]" 		 */
/*	Then store the remainder string in info->nextstr */
void	gnl_extract(char *buffer, t_gnl *info)
{
	info->index = 0;
	info->wc = 0;
	while (buffer[info->wc] != '\n')
		info->wc++;
	info->wc++;
	info->finalstr = malloc(sizeof(char) * (info->wc + 1));
	info->finalstr[info->wc] = '\0';
	while (--info->wc >= 0)
	{
		info->finalstr[info->index] = buffer[info->index];
		info->index++;
	}
	if (buffer[info->index])
	{
		info->nextstr = gnl_strdup(&buffer[info->index], 2);
		free(buffer);
		return ;
	}
	info->nextstr = NULL;
	free(buffer);
}

/*	First looks into the nextstr stored inside arry[fd],		*/
/*	Checks if there is a '\n' present in the nexstr.			*/
/*																*/
/*	IF '\n' IS PRESENT INSIDE OF ARRY[FD]						*/
/*	Use gnl_extract() to get the finalstr						*/
/*																*/
/*	IF '\n' IS NOT PRESENT INSIDE OF ARRY[FD]					*/
/*	Make a duplicate of arry[fd] and store it in				*/
/*	info->finalstr as this is also the start of a new string	*/
void	gnl_extract_and_join(int fd, char **arry, t_gnl *info, char *buffer)
{
	if (gnl_checks(arry[fd]))
	{
		gnl_extract(arry[fd], info);
		arry[fd] = info->nextstr;
		free(buffer);
	}
	else
	{
		info->finalstr = gnl_strdup(arry[fd], 2);
		free(arry[fd]);
		gnl_finalstr(fd, buffer, info);
		arry[fd] = gnl_strsort(buffer, info);
		free(buffer);
	}
}

/*	Get . Next . Line .	*/
char	*get_next_line(int fd)
{
	static char	*arry[1024];
	char		*buffer;
	t_gnl		info;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	info.finalstr = NULL;
	if (arry[fd])
	{
		free(info.finalstr);
		gnl_extract_and_join(fd, arry, &info, buffer);
		return (info.finalstr);
	}
	gnl_finalstr(fd, buffer, &info);
	if (info.readwc < 0)
	{
		free(buffer);
		return (NULL);
	}
	arry[fd] = gnl_strsort(buffer, &info);
	free(buffer);
	return (info.finalstr);
}
