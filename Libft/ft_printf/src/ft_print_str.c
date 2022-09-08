/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:15:19 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_minus_dot(t_pf *info, char *args);
void	ft_s_only_dot(t_flags *f, t_pf *info, char *args);
void	ft_s_only_minus(t_pf *info, char *args);
void	ft_print_null(t_flags *f, t_pf *info);

void	ft_print_str(t_flags *f, t_pf *info, char *args)
{
	info->format = args;
	if (args == NULL)
	{
		ft_print_null(f, info);
		return ;
	}
	if ((f->dot >= 1) && (f->minus >= 1))
		ft_s_minus_dot(info, args);
	else if (f->dot >= 1)
		ft_s_only_dot(f, info, args);
	else if (f->minus >= 1)
		ft_s_only_minus(info, args);
	else if (info->width)
		ft_only_width(f, info, " ");
	else
	{
		ft_putstr_fd(args, 1);
		info->wc = ft_strlen((const char *)args);
	}
}

void	ft_s_minus_dot(t_pf *info, char *args)
{
	info->strlen = ft_strlen((const char *)args);
	if (info->precision >= info->strlen)
		ft_minus_width(info);
	else
	{
		info->format = ft_substr(args, 0, info->precision);
		ft_minus_width(info);
		free(info->format);
	}
}

void	ft_s_only_dot(t_flags *f, t_pf *info, char *args)
{
	info->strlen = ft_strlen((const char *)args);
	if (info->precision >= info->strlen)
		ft_only_width(f, info, " ");
	else
	{
		info->format = ft_substr(args, 0, info->precision);
		ft_only_width(f, info, " ");
		free(info->format);
	}
}

void	ft_s_only_minus(t_pf *info, char *args)
{
	info->strlen = ft_strlen(args);
	if (info->strlen >= info->width)
	{
		ft_putstr_fd(args, 1);
		info->wc = info->strlen;
	}
	else
	{
		ft_putstr_fd(args, 1);
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
	}
}

void	ft_print_null(t_flags *f, t_pf *info)
{
	char	*null;

	null = "(null)";
	if (f->dot)
	{
		while ((info->precision > 0) && (*null != '\0'))
		{
			write(1, null, 1);
			null++;
			info->precision--;
			info->wc++;
		}
	}
	else if (info->width >= 6)
	{
		info->format = null;
		ft_only_width(f, info, " ");
	}
	else
	{
		ft_putstr_fd(null, 1);
		info->wc = 6;
	}
}
