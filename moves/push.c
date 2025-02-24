/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:50:35 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/23 13:54:01 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	push(t_list **src, t_list **dst, int print)
{
	t_list	*src_head;
	t_list	*next;
	t_list	*last;

	if (!*src)
		return ;
	src_head = *src;
	if (src_head->next == src_head)
		*src = NULL;
	else
	{
		next = src_head->next;
		last = src_head->prev;
		next->prev = last;
		last->next = next;
		*src = next;
	}
	src_head->next = NULL;
	src_head->prev = NULL;
	ft_lstadd_front(dst, src_head);
	if (print == 1)
		ft_putstr_fd("pb\n", 1);
	else if (print == 2)
		ft_putstr_fd("pa\n", 1);
}
