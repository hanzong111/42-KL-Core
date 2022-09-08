/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:09:38 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_width(t_pf *info)
{
	info->wc = info->width;
	info->strlen = ft_strlen((const char *)info->format);
	if (info->width < info->strlen)
	{
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->width = info->width - info->strlen;
		ft_putstr_fd(info->format, 1);
		while (--info->width >= 0)
			write(1, " ", 1);
	}
}
