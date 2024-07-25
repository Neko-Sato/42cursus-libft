/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:40:49 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/26 00:43:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>

typedef struct s_stack
{
	struct s_stack	pre;
	size_t			size;
	char			data[];
}					t_stack;

int					ft_stack_push(t_stack **stack, void *src, size_t size);
void				ft_stack_pop(t_stack **stack, void *dst);

#endif
