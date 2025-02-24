/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:48 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/25 21:20:07 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "moves.h"
#include "sorting.h"

static int	smallest(t_list *stack)
{
	int		smallest;
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	smallest = current->index;
	while (current->next != stack)
	{
		current = current->next;
		if (current->index < smallest)
			smallest = current->index;
	}
	if (current->index < smallest)
		smallest = current->index;
	return (smallest);
}

int	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		return (sort_three(stack_a));
	while (size > 3)
	{
		min = smallest(*stack_a);
		while ((*stack_a)->index != min)
		{
			if ((*stack_a)->next->index == min)
				rotate(stack_a, 1);
			else
				r_rotate(stack_a, 1);
		}
		push(stack_a, stack_b, 1);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 2);
	return (0);
}
