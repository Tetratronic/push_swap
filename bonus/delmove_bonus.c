/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:13:50 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/29 20:07:52 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	delmove(t_moves *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->move);
	free(lst);
	lst = NULL;
}
