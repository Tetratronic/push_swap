/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:41:06 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:53 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

void	swap(t_list **stack, int print);
void	rotate(t_list **stack, int print);
void	r_rotate(t_list **stack, int print);
void	push(t_list **from, t_list **to, int print);
void	ss(t_list **stack_a, t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);

#endif
