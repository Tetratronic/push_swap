/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:14:05 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 16:24:07 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"
#include "chunks_local.h"

static int	get_pos(t_list *stack, int target_index)
{
	t_list	*current;
	int		position;

	position = 0;
	current = stack;
	if (current->index == target_index)
		return (position);
	current = current->next;
	position++;
	while (current != stack)
	{
		if (current->index == target_index)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

static int	find_max_index(t_list *stack)
{
	t_list	*current;
	int		max_index;

	current = stack;
	max_index = stack->index;
	if (current->index > max_index)
		max_index = current->index;
	current = current->next;
	while (current != stack)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		while ((*stack_b)->index != max_index)
		{
			if (get_pos(*stack_b, max_index) <= ft_lstsize(*stack_b) / 2)
				rotate(stack_b, 2);
			else
				r_rotate(stack_b, 2);
		}
		push(stack_b, stack_a, 2);
	}
}
