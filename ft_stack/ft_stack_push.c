/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:36:34 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/26 00:40:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <ft_string.h>
#include <stdlib.h>

int	ft_stack_push(t_stack **stack, void *src, size_t size)
{
	t_stack	*node;

	node = malloc(sizeof(*node) + size);
	if (!node)
		return (-1);
	node->pre = *stack;
	node->size = size;
	ft_memcpy(node->data, src, size);
	*stack = node;
	return (0);
}
