/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:46:29 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/25 18:14:40 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

int		chunk_sort(t_list **stack_a, t_list **stack_b, int size);
int		sort_small(t_list **stack_a, t_list **stack_b);
int		sort_three(t_list **stack);
int		sortarr(int *arr, int size);

#endif
