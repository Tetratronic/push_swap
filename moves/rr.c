/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:28:16 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:37 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "moves.h"

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
