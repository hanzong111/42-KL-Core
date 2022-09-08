/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:05:17 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_lower_hexa(t_flags *f, t_pf *info, unsigned int args)
{
	ft_convert_hex(f, info, args);
	info->strlen = info->wc;
	if (f->minus && f->dot)
		ft_minus_dot(f, info, "0x");
	else if (f->dot)
		ft_only_dot(f, info, "0x");
	else if (f->minus)
		ft_only_minus(f, info, "0x");
	else if (f->zero)
		ft_only_zero(f, info, "0x");
	else if (info->width)
		ft_only_width(f, info, "0x");
	else
	{
		if (f->hash && *info->format != '0')
		{
			ft_putstr_fd("0x", 1);
			info->wc += 2;
		}
		ft_putstr_fd(info->format, 1);
	}
	free(info->format);
}
