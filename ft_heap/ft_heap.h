/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:37:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:19:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H
# define FT_HEAP_H

# include <stddef.h>

typedef struct s_heap_args
{
	void	*base;
	size_t	nmemb;
	size_t	size;
	int		(*compar)(const void *, const void *);
	void	(*swap)(void *, void *);
}			t_heap_args;

void		ft_heapify(t_heap_args *args);
void		ft_heap_push(t_heap_args *args);
void		ft_heap_pop(t_heap_args *args);

void		ft__heap_shiftup(t_heap_args *args, size_t index);
void		ft__heap_shiftdown(t_heap_args *args, size_t index);
void		ft__heap_swap(t_heap_args *args, void *a, void *b);

#endif
