/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:24:36 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:36 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	ss(t_list **stack_a, t_list **stack_b, int print)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
