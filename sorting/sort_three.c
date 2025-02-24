/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:47 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 10:46:02 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"
#include "sorting.h"

static int	get_largest(t_list *stack)
{
	int		largest;
	int		index;
	int		i;
	t_list	*head;

	largest = stack->index;
	index = 0;
	head = stack;
	i = 0;
	while (stack->next != head)
	{
		if (stack->index > largest)
		{
			largest = stack->index;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	if (stack->index > largest)
	{
		largest = stack->index;
		index = i;
	}
	return (index);
}

int	sort_three(t_list **stack)
{
	int	largest;
	int	size;

	size = ft_lstsize(*stack);
	if (size > 3)
		return (0);
	largest = get_largest(*stack);
	if (largest == 0)
		rotate(stack, 1);
	else if (largest == 1)
		r_rotate(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 1);
	return (0);
}
