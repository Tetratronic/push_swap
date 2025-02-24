/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:01:07 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 16:38:03 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*lst)->prev;
		new->next = *lst;
		new->prev = last;
		(*lst)->prev = new;
		last->next = new;
	}
	*lst = new;
}
