/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:00:02 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_upper(char *str);

void	ft_print_upper_hexa(t_flags *f, t_pf *info, unsigned int args)
{
	ft_convert_hex(f, info, (unsigned int)args);
	ft_str_upper(info->format);
	info->strlen = info->wc;
	if (f->minus && f->dot)
		ft_minus_dot(f, info, "0X");
	else if (f->dot)
		ft_only_dot(f, info, "0X");
	else if (f->minus)
		ft_only_minus(f, info, "0X");
	else if (f->zero)
		ft_only_zero(f, info, "0X");
	else if (info->width)
		ft_only_width(f, info, "0X");
	else
	{
		if (f->hash && *info->format != '0')
		{
			ft_putstr_fd("0X", 1);
			info->wc += 2;
		}
		ft_putstr_fd(info->format, 1);
	}
	free(info->format);
}

void	ft_str_upper(char *str)
{
	while (*str != '\0')
	{
		*str = (char)ft_toupper((int)*str);
		str++;
	}
}
