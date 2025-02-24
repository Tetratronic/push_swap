/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:35:34 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 16:22:04 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;
	t_list	*first;

	if (!lst || !*lst)
		return ;
	first = *lst;
	current = *lst;
	while (current && current->next != first)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (current)
		free(current);
	*lst = NULL;
}
