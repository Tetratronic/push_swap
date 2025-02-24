/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:38:39 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 16:43:08 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	rotate(t_list **stack, int print)
{
	t_list	*second;

	if (!*stack)
		return ;
	second = (*stack)->next;
	*stack = second;
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
	else if (print == 2)
		ft_putstr_fd("rb\n", 1);
}
