/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:02:49 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/24 16:42:40 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

typedef struct s_info
{
	int				wc;
	int				width;
	int				strlen;
	char			*str;
	char			*format;
	char			*prefix;
	int				precision;
}	t_info;

int		ft_printf(const char *str, ...);
void	ft_initializeflags(t_flags *var, t_info *info);
void	ft_flagscheck(char c, char d, t_flags *flags);
int		ft_typecheck(char c);
void	ft_precision_width(char *str, t_flags *f, t_info *info);

void	ft_convert_ptr(t_info *info, unsigned long long i);
void	ft_convert_hex(t_flags *f, t_info *info, unsigned int i);

void	ft_print_percent(t_flags *flags, t_info *info);
void	ft_print_char(t_flags *f, t_info *info, int c);
void	ft_print_str(t_flags *f, t_info *info, char *args);
void	ft_print_pointer(t_flags *f, t_info *info, unsigned long long args);
void	ft_print_upper_hexa(t_flags *f, t_info *info, unsigned int args);
void	ft_print_lower_hexa(t_flags *f, t_info *info, unsigned int args);
void	ft_print_nbr(t_flags *f, t_info *info, int i);
void	ft_print_unbr(t_flags *f, t_info *info, unsigned int args);

void	ft_minus_width(t_info *info);
void	ft_minus_dot(t_flags *f, t_info *info, char *type);
void	ft_only_zero(t_flags *f, t_info *info, char *c);
void	ft_only_width(t_flags *f, t_info *info, char *c);
void	ft_only_dot(t_flags *f, t_info *info, char *type);
void	ft_only_minus(t_flags *f, t_info *info, char *c);

#endif