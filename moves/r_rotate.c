/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:45:38 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 16:43:22 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	r_rotate(t_list **stack, int print)
{
	t_list	*last;

	if (!*stack)
		return ;
	last = ft_lstlast(*stack);
	*stack = last;
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rrb\n", 1);
}
