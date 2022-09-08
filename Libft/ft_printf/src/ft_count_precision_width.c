/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_precision_width.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:18:36 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_pf *info, char *str);
void	ft_width(t_pf *info, char *str);
void	ft_no_precision_width(t_pf *info, char *str);

/*	ft_precision_width()-> To extract the width and precision value .		*/
/*	Example	:	%10.30s														*/
/*				f->width = 10;												*/
/*				f->precision = 30;											*/

void	ft_precision_width(char *str, t_flags *f, t_pf *info)
{
	str++;
	if (f->dot)
	{
		if (*str == '.')
		{
			info->width = 0;
			ft_precision(info, str);
		}
		else
		{
			ft_width(info, str);
			if (!ft_typecheck(*info->str + 1))
				info->precision = 0;
			else
				ft_precision(info, info->str);
		}
	}
	else
		ft_no_precision_width(info, str);
}

void	ft_width(t_pf *info, char *str)
{
	while (*str == '-' || *str == '#' || *str == '0' || *str == ' ')
		str++;
	info->width = ft_atoi(str);
	while (*str != '.')
		str++;
	info->str = str;
}

void	ft_precision(t_pf *info, char *str)
{
	str++;
	info->precision = ft_atoi(str);
	while (ft_typecheck(*str))
		str++;
	info->str = str;
}

void	ft_no_precision_width(t_pf *info, char *str)
{
	while (*str == '-' || *str == '#' || *str == '0' || *str == ' ')
		str++;
	info->width = ft_atoi(str);
	while (ft_typecheck(*str))
		str++;
	info->str = str;
}
