/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:34:34 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/30 11:29:15 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include "../includes/moves.h"

typedef struct s_moves
{
	char				*move;
	struct s_moves		*next;
}						t_moves;

t_list	*valid_stack(int argc, char **argv);
t_moves	*new(char *content);
void	clear(t_moves **lst, void (*del)(void *));
void	delmove(t_moves *lst, void (*del)(void *));
void	append(t_moves **lst, t_moves *new);
void	execute(t_list **stack_a, t_list **stack_b, char *move);
void	cleanup(t_list **stack_a, t_list **stack_b);
int		error(t_list **stack_a, t_list **stack_b, t_moves **moves);
int		valid(char *move);
void	apply_moves(t_list **stack_a, t_list **stack_b, t_moves *moves);
t_moves	*last(t_moves *lst);

#endif
