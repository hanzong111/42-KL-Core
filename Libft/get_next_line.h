/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:39 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_gnl
{
	char	*finalstr;
	char	*bufferstr;
	char	*nextstr;
	int		index;
	int		wc;
	int		wc1;
	int		wc2;
	int		readwc;
}	t_gnl;

char	*get_next_line(int fd);
void	gnl_strlen(char *str1, char *str2, t_gnl *info);
void	gnl_strjoin(char *buffer, t_gnl *info);
void	gnl_strcopy(char *str, char *bufferstr, int len, int type);
char	*gnl_strdup(char *newstr, int type);
char	*gnl_finalstr(int fd, char *buffer, t_gnl *info);
int		gnl_checks(char *buffer);

#endif