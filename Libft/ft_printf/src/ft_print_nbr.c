/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:42:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix(t_flags *f, t_pf *info, int i);
void	ft_convert_nbr(t_flags *f, t_pf *info, int i);
void	ft_no_flags(t_flags *f, t_pf *info, int i);

void	ft_print_nbr(t_flags *f, t_pf *info, int i)
{
	ft_convert_nbr(f, info, i);
	info->strlen += ft_strlen((const char *)info->format);
	info->wc = info->strlen;
	ft_prefix(f, info, i);
	if (f->minus && f->dot)
		ft_minus_dot(f, info, info->prefix);
	else if (f->dot)
		ft_only_dot(f, info, info->prefix);
	else if (f->minus)
		ft_only_minus(f, info, info->prefix);
	else if (f->zero)
		ft_only_zero(f, info, info->prefix);
	else if (info->width)
		ft_only_width(f, info, info->prefix);
	else
		ft_no_flags(f, info, i);
	if (i >= 0)
		free(info->format);
	else
		free(info->format - 1);
	free(info->prefix);
}

void	ft_convert_nbr(t_flags *f, t_pf *info, int i)
{
	char	*s;

	if ((!info->precision && f->dot) && i == 0)
	{
		info->format = malloc(sizeof(char) * 1);
		*info->format = '\0';
		return ;
	}
	s = ft_itoa(i);
	if (i < 0)
	{
		s++;
		info->strlen++;
	}
	info->format = s;
}

void	ft_prefix(t_flags *f, t_pf *info, int i)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	info->prefix = s;
	if (i >= 0)
	{
		if (f->plus)
			*s = '+';
		else if (f->space)
			*s = ' ';
		else
			*s = '\0';
	}
	else
	{
		*s = '-';
		f->space = 1;
	}
	s++;
	*s = '\0';
	return ;
}

void	ft_no_flags(t_flags *f, t_pf *info, int i)
{
	if (i < 0)
		ft_putchar_fd('-', 1);
	else if (f->space || f->plus)
	{
		ft_putstr_fd(info->prefix, 1);
		info->wc++;
	}
	ft_putstr_fd(info->format, 1);
}
