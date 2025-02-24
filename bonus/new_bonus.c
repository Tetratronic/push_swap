/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:22:11 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/29 20:08:17 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_moves	*new(char *content)
{
	t_moves	*result;

	result = (t_moves *)malloc(sizeof(t_moves));
	if (!result)
		return (NULL);
	result->move = content;
	result->next = NULL;
	return (result);
}
