/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:51:26 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_nbr_len(t_pf *info, unsigned long long i);

void	ft_convert_ptr(t_pf *info, unsigned long long i)
{
	char	*str;
	int		index;

	ft_ptr_nbr_len(info, i);
	index = info->wc;
	str = malloc(sizeof(char) * (info->wc + 1));
	if (!str)
		return ;
	str[index] = '\0';
	index--;
	while (i >= 16)
	{
		str[index] = "0123456789abcdef"[i % 16];
		i = i / 16;
		index--;
	}
	str[index] = "0123456789abcdef"[i];
	info->format = str;
}

void	ft_ptr_nbr_len(t_pf *info, unsigned long long i)
{
	while (i >= 16)
	{
		i = i / 16;
		info->wc++;
	}
	info->wc++;
}
