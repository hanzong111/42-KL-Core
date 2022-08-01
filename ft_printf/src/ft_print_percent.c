/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:52:56 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/17 18:18:47 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_minus_zero(t_info *info);
void	ft_p_only_zero(t_info *info);
void	ft_p_only_width(t_info *info);

/*	Seperated the conditions so that we know how to extract the 'Width' */
/*	from the string														*/
/*																		*/
/*	ft_print_minus_zero() -> For when flags - & 0 are present together	*/
/*	Example :	%-010%													*/
/*	ft_print_zero -> For when 0 flag is present and width 				*/
/*	Example :	%010%													*/
/*				%10%													*/

void	ft_print_percent(t_flags *flags, t_info *info)
{
	if ((flags->minus && flags->zero) || flags->minus)
		ft_p_minus_zero(info);
	else if (flags->zero)
		ft_p_only_zero(info);
	else if (info->width)
		ft_p_only_width(info);
	else
	{
		write(1, "%%", 1);
		info->wc = 1;
	}	
}

void	ft_p_minus_zero(t_info *info)
{
	write(1, "%%", 1);
	if (info->width == 0)
	info->wc = 1;
	else
		info->wc = info->width;
	while (--info->width > 0)
		write(1, " ", 1);
}

void	ft_p_only_zero(t_info *info)
{
	info->wc = info->width;
	while (--info->width > 0)
		write(1, "0", 1);
	write(1, "%%", 1);
}

void	ft_p_only_width(t_info *info)
{
	info->wc = info->width;
	while (--info->width > 0)
		write(1, " ", 1);
	write(1, "%%", 1);
}
