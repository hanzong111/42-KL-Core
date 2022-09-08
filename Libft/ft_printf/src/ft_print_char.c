/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:27:27 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_minus_width(t_pf *info, int c);
void	ft_c_only_width(t_pf *info, int c);

void	ft_print_char(t_flags *f, t_pf *info, int c)
{
	if (f->minus >= 1)
		ft_c_minus_width(info, c);
	else if (info->width)
		ft_c_only_width(info, c);
	else
	{
		write(1, &c, 1);
		info->wc = 1;
	}
}

void	ft_c_minus_width(t_pf *info, int c)
{
	if (info->width == 0)
	{
		write(1, &c, 1);
		info->wc = 1;
		return ;
	}
	else
	{
		info->wc = info->width;
		info->width = info->width - 1;
		write(1, &c, 1);
		while (--info->width >= 0)
			write(1, " ", 1);
	}
}

void	ft_c_only_width(t_pf *info, int c)
{
	info->wc = info->width;
	info->width = info->width - 1;
	while (--info->width >= 0)
		write(1, " ", 1);
	write(1, &c, 1);
}
