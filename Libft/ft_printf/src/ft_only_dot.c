/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:29:40 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bigger(t_flags *f, t_pf *info, char *type);
void	ft_bigger2(t_flags *f, t_pf *info, char *type);
void	ft_smaller(t_flags *f, t_pf *info, char *type);
void	ft_print_prefix(t_flags *f, t_pf *info, char *type);

void	ft_only_dot(t_flags *f, t_pf *info, char *type)
{
	if (!info->precision)
	{
		if (f->hash || f->plus || f->space)
		{
			if (f->hash)
				info->strlen = info->strlen + 2;
			ft_putstr_fd(type, 1);
		}
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
		info->width -= info->wc;
		while (--info->width >= 0)
		{
			write(1, " ", 1);
			info->wc++;
		}
		return ;
	}
	if (info->width >= info->precision)
		ft_bigger(f, info, type);
	else
		ft_smaller(f, info, type);
}

void	ft_bigger(t_flags *f, t_pf *info, char *type)
{
	if (info->precision >= info->strlen)
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		info->precision -= info->wc;
		if (f->plus || f->space)
			info->precision++;
		info->strlen += info->precision;
		info->width -= info->strlen;
		while (--info->width >= 0)
			info->wc += write(1, " ", 1);
		if (f->hash || f->plus || f->space)
			ft_putstr_fd(type, 1);
		while (--info->precision >= 0)
			info->wc += write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}
	else
		ft_bigger2(f, info, type);
}

void	ft_bigger2(t_flags *f, t_pf *info, char *type)
{
	if (f->hash)
		info->strlen = info->strlen + 2;
	info->width -= info->strlen;
	while (--info->width >= 0)
		info->wc += write(1, " ", 1);
	if (f->hash || f->plus || f->space)
		ft_putstr_fd(type, 1);
	ft_putstr_fd(info->format, 1);
	if (!info->precision)
		info->wc = info->width;
}

void	ft_smaller(t_flags *f, t_pf *info, char *type)
{
	if (info->precision >= info->strlen)
	{
		ft_print_prefix(f, info, type);
		info->strlen = info->precision - info->wc;
		while (--info->strlen >= 0)
			info->wc += write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}		
	else
	{
		ft_print_prefix(f, info, type);
		ft_putstr_fd(info->format, 1);
	}
}

void	ft_print_prefix(t_flags *f, t_pf *info, char *type)
{
	if (f->hash || f->plus || f->space)
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
			info->precision++;
		ft_putstr_fd(type, 1);
	}
}
