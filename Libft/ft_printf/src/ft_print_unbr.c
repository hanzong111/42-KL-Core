/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:33:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_unbr(t_flags *f, t_pf *info, unsigned int i);
int		ft_udigitcount(unsigned int n);
char	*ft_uitoa(unsigned int n);

void	ft_print_unbr(t_flags *f, t_pf *info, unsigned int i)
{
	ft_convert_unbr(f, info, i);
	info->strlen += ft_strlen(info->format);
	info->wc = info->strlen;
	if (f->minus && f->dot)
		ft_minus_dot(f, info, "");
	else if (f->dot)
		ft_only_dot(f, info, "");
	else if (f->minus)
		ft_only_minus(f, info, "");
	else if (f->zero)
		ft_only_zero(f, info, "");
	else if (info->width)
		ft_only_width(f, info, "");
	else
		ft_putstr_fd(info->format, 1);
	free(info->format);
}

void	ft_convert_unbr(t_flags *f, t_pf *info, unsigned int i)
{
	if ((!info->precision && f->dot) && i == 0)
	{
		info->format = malloc(sizeof(char) * 1);
		*info->format = '\0';
		return ;
	}
	info->format = ft_uitoa(i);
}

int	ft_udigitcount(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n > 0 || (n == 0 && count == 0))
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				count;
	unsigned int	dummy;

	count = ft_udigitcount(n);
	str = (char *)malloc (sizeof(char) * (count + 1));
	if (!str)
		return (0);
	str[count] = '\0';
	dummy = 0;
	while (--count >= 0)
	{
		dummy = n % 10;
		n = n / 10;
		str[count] = dummy + '0';
	}
	return (str);
}
