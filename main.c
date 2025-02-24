/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:00:28 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 12:58:03 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"
#include "sorting.h"
#include "moves.h"

static void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

static int	sorted(t_list *stack_a)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(stack_a);
	while (i < size - 1)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

static int	indexify(t_list *stack_a)
{
	int	*arr;
	int	size;
	int	i;

	size = ft_lstsize(stack_a);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i++] = stack_a->nb;
		stack_a = stack_a->next;
	}
	sortarr(arr, size);
	while (--i >= 0)
	{
		while (stack_a->nb != arr[i])
			stack_a = stack_a->next;
		stack_a->index = i;
	}
	free(arr);
	arr = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = valid_stack(argc, argv);
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	indexify(stack_a);
	if (sorted(stack_a))
		;
	else if (size <= 16)
		sort_small(&stack_a, &stack_b);
	else
		chunk_sort(&stack_a, &stack_b, size);
	cleanup(&stack_a, &stack_b);
	return (0);
}
