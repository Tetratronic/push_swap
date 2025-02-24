/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:15:39 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 22:15:53 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "parsing.h"

static t_list	*get_stack(int argc, char **argv)
{
	int		i;
	t_list	*stack;
	t_list	*node;

	stack = NULL;
	while (--argc)
	{
		i = 0;
		if (!(*++argv)[i])
			return (ft_lstclear(&stack), NULL);
		while ((*argv)[i])
		{
			while ((*argv)[i] && (*argv)[i] == ' ')
				i++;
			if (!(*argv)[i])
				break ;
			node = ft_lstnew(ft_atoi((&(*argv)[i])));
			if (!node || (node->nb == (long)2147483647 + 1))
				return (ft_lstclear(&stack), NULL);
			ft_lstadd_back(&stack, node);
			while ((*argv)[i] && ft_strchr("0123456789+-", (*argv)[i]))
				i++;
		}
	}
	return (stack);
}

static int	valid_args(int argc, char **args)
{
	int	i;

	while (--argc)
	{
		i = 0;
		args++;
		while ((*args)[i])
		{
			if (!ft_strchr("0123456789+- ", (*args)[i]))
				return (0);
			if ((*args)[i] == '-' || (*args)[i] == '+')
				if (!ft_isdigit((*args)[i + 1])
				|| (i != 0 && (*args)[i - 1] != ' '))
					return (0);
			i++;
		}
	}
	return (1);
}

static int	duplicates(t_list *stack)
{
	t_list	*head;
	t_list	*tail;

	head = stack;
	tail = ft_lstlast(stack);
	while (stack->next != head)
	{
		while (tail != stack)
		{
			if (stack->nb == tail->nb)
				return (1);
			tail = tail->prev;
		}
		stack = stack->next;
	}
	return (0);
}

t_list	*valid_stack(int argc, char **argv)
{
	t_list	*stack;

	if (argc < 2)
		exit(0);
	if (!valid_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	stack = get_stack(argc, argv);
	if (!stack || duplicates(stack))
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(&stack);
		exit(-1);
	}
	return (stack);
}
