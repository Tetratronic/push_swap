/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:29:00 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:21 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	r_rotate(stack_a, 0);
	r_rotate(stack_b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
