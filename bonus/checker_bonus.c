/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:38:40 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/30 11:20:19 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "gnl/get_next_line.h"

static int	sorted(t_list *stack_a)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(stack_a);
	if (!stack_a || size == 1)
		return (1);
	while (i < size - 1)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

int	store_moves(t_moves **moves)
{
	char	*move;
	t_moves	*node;

	while (1)
	{
		move = get_next_line(0, 0);
		if (!move)
			break ;
		if (valid(move))
		{
			node = new(ft_strdup(move));
			if (!node || !node->move)
				return (clean(&move), get_next_line(0, 1), 0);
			append(moves, node);
			clean(&move);
		}
		else
			return (clean(&move), get_next_line(0, 1), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_moves		*moves;

	stack_a = valid_stack(argc, argv);
	stack_b = NULL;
	moves = NULL;
	if (!store_moves(&moves))
		return (error(&stack_a, &stack_b, &moves));
	apply_moves(&stack_a, &stack_b, moves);
	if (!stack_b && sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	cleanup(&stack_a, &stack_b);
	clear(&moves, free);
	return (0);
}
