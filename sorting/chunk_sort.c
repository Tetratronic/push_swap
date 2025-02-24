/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:44:03 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 17:23:40 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"
#include "sorting.h"
#include "chunks_local.h"

static void	push_rotate(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, 1);
	rotate(stack_b, 2);
}

static void	partition(t_list **stack_a, t_list **stack_b, int csize, int order)
{
	int	moved_elements;
	int	size;

	moved_elements = 0;
	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= moved_elements)
		{
			push(stack_a, stack_b, 1);
			moved_elements++;
		}
		else if ((*stack_a)->index < moved_elements + csize)
		{
			push_rotate(stack_a, stack_b);
			moved_elements++;
		}
		else
		{
			if (order > size / 3)
				r_rotate(stack_a, 1);
			else
				rotate(stack_a, 1);
		}
	}
}

static int	dominant_side(t_list *lst)
{
	int	ascending;
	int	middle;
	int	i;

	ascending = 0;
	i = 0;
	middle = ft_lstsize(lst) / 2;
	while (i < middle)
	{
		if (lst->nb < lst->next->nb)
			ascending--;
		ascending++;
		lst = lst->next;
		i++;
	}
	return (ascending);
}

int	chunk_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_count;
	int	chunk_size;
	int	order;

	order = dominant_side(*stack_a);
	chunk_count = 1;
	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 15;
	chunk_size = ft_lstsize(*stack_a) / chunk_count;
	partition(stack_a, stack_b, chunk_size, order);
	push_back_to_a(stack_a, stack_b);
	return (0);
}
