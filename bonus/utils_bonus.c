/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:10:01 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/30 11:20:14 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(stack_a, 0);
	else if (!ft_strcmp(move, "sb\n"))
		swap(stack_b, 0);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(stack_a, 0);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(stack_b, 0);
	else if (!ft_strcmp(move, "rra\n"))
		r_rotate(stack_a, 0);
	else if (!ft_strcmp(move, "rrb\n"))
		r_rotate(stack_b, 0);
	else if (!ft_strcmp(move, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strcmp(move, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(move, "pb\n"))
		push(stack_a, stack_b, 0);
	else if (!ft_strcmp(move, "pa\n"))
		push(stack_b, stack_a, 0);
}

void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

int	error(t_list **stack_a, t_list **stack_b, t_moves **moves)
{
	write(2, "Error\n", 6);
	cleanup(stack_a, stack_b);
	clear(moves, free);
	moves = NULL;
	return (-1);
}

int	valid(char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		return (1);
	if (!ft_strcmp(move, "sb\n"))
		return (1);
	if (!ft_strcmp(move, "ra\n"))
		return (1);
	if (!ft_strcmp(move, "rb\n"))
		return (1);
	if (!ft_strcmp(move, "rra\n"))
		return (1);
	if (!ft_strcmp(move, "rrb\n"))
		return (1);
	if (!ft_strcmp(move, "rr\n"))
		return (1);
	if (!ft_strcmp(move, "rrr\n"))
		return (1);
	if (!ft_strcmp(move, "ss\n"))
		return (1);
	if (!ft_strcmp(move, "pb\n"))
		return (1);
	if (!ft_strcmp(move, "pa\n"))
		return (1);
	else
		return (0);
}

void	apply_moves(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	while (moves)
	{
		execute(stack_a, stack_b, moves->move);
		moves = moves->next;
	}
}
