/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:35:35 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typecheck(char c)
{
	if (c == 'c')
		return (0);
	else if (c == 's')
		return (0);
	else if (c == 'p')
		return (0);
	else if (c == 'd')
		return (0);
	else if (c == 'i')
		return (0);
	else if (c == 'u')
		return (0);
	else if (c == 'x')
		return (0);
	else if (c == 'X')
		return (0);
	else if (c == '%')
		return (0);
	else
		return (1);
}

void	ft_flagscheck(char c, char d, t_flags *flags)
{
	if (c == '-')
		flags->minus++;
	else if (c == '0' && !(d >= '0' && d <= '9'))
		flags->zero++;
	else if (c == '.')
		flags->dot++;
	else if (c == '#')
		flags->hash++;
	else if (c == ' ')
		flags->space++;
	else if (c == '+')
		flags->plus++;
	else
		return ;
}

void	ft_initializeflags(t_flags *var, t_pf *info)
{
	var->minus = 0;
	var->zero = 0;
	var->dot = 0;
	var->hash = 0;
	var->space = 0;
	var->plus = 0;
	info->wc = 0;
	info->width = 0;
	info->precision = 0;
	info->strlen = 0;
}
