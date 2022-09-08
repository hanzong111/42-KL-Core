/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:51:45 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_po_only_width(t_pf *info);

void	ft_print_pointer(t_flags *f, t_pf *info, unsigned long long args)
{
	ft_convert_ptr(info, args);
	info->wc = info->wc + 2;
	f->hash = 1;
	if (f->minus >= 1)
		ft_only_minus(f, info, "0x");
	else if (info->width)
		ft_po_only_width(info);
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(info->format, 1);
	}
	free(info->format);
}

void	ft_po_only_width(t_pf *info)
{
	if (info->wc >= info->width)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(info->format, 1);
	}
	else
	{
		info->strlen = info->width;
		info->width = info->width - info->wc;
		while (--info->width >= 0)
			write(1, " ", 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
}
