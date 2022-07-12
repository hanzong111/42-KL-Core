/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:39:50 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/11 18:12:14 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlst;

	lastlst = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (lastlst)
	{
		if (lastlst->next == NULL)
		{
			lastlst->next = new;
			break ;
		}
		lastlst = lastlst->next;
	}
}
