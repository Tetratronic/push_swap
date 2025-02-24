/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:06:25 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/29 20:06:43 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	append(t_moves **lst, t_moves *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		last(*lst)->next = new;
}
