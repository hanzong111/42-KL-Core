/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:01:40 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_zero(t_flags *f, t_pf *info, char *c);
void	ft_only_width(t_flags *f, t_pf *info, char *c);

void	ft_only_minus(t_flags *f, t_pf *info, char *c)
{
	if (f->hash || f->plus || f->space)
		ft_putstr_fd(c, 1);
	if (info->wc >= info->width)
		ft_putstr_fd(info->format, 1);
	else
	{
		ft_putstr_fd(info->format, 1);
		info->strlen = info->wc;
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
	}
}

void	ft_only_width(t_flags *f, t_pf *info, char *c)
{
	info->strlen = ft_strlen((const char *)info->format);
	if (f->hash)
		info->strlen += 2;
	if (f->plus || f->space)
		info->strlen++;
	if (info->width < info->strlen)
	{
		if (f->hash || f->plus || f->space)
			ft_putstr_fd(c, 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
		if (f->hash || f->plus || f->space)
			ft_putstr_fd(c, 1);
		ft_putstr_fd(info->format, 1);
	}
}

void	ft_only_zero(t_flags *f, t_pf *info, char *c)
{
	info->strlen = ft_strlen((const char *)info->format);
	if (f->hash || f->plus || f->space)
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
			info->strlen++;
		ft_putstr_fd(c, 1);
	}
	if (info->width < info->strlen)
	{
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}
}
