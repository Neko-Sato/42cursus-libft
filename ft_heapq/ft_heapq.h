/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:37:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:16:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAPQ_H
# define FT_HEAPQ_H

# include <stddef.h>

typedef struct s_heapq
{
	void	*base;
	size_t	nmemb;
	size_t	size;
	int		(*less)(const void *, const void *);
	void	(*swap)(void *, void *);
}			t_heapq;

void		ft_heapify(t_heapq *args);
void		ft_heapq_push(t_heapq *args);
void		ft_heapq_pop(t_heapq *args);

void		ft__heapq_shiftup(t_heapq *args, size_t index);
void		ft__heapq_shiftdown(t_heapq *args, size_t index);
void		ft__heapq_swap(t_heapq *args, void *a, void *b);

#endif
