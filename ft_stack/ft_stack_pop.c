/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:36:34 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/26 00:43:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <ft_string.h>
#include <stdlib.h>

void	ft_stack_pop(t_stack **stack, void *dst)
{
	t_stack	*node;

	node = *stack;
	ft_memcpy(dst, node->data, node->size);
	*stack = node->pre;
	free(node);
}
