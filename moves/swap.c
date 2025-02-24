/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:05:26 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:28 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	swap(t_list **stack, int print)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*stack = second;
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
	else if (print == 2)
		ft_putstr_fd("sb\n", 1);
}
