/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:22:21 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/16 15:51:19 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*head;

	if (!lst)
		return (0);
	result = 1;
	head = lst;
	while (lst->next != head)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}
