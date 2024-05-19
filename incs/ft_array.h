/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/29 20:35:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

void	*ft_ndarraynew(size_t size, size_t shape[], size_t ndim);
void	ft_ndarraydel(void *array, size_t ndim);

void	*ft_2darraynew(size_t size, size_t width, size_t height);
void	ft_2darraydel(void *array);

int		ft_average(int array[], size_t len);
void	ft_sort(int array[], size_t len);
int		ft_issorted(int array[], size_t len, int asc);
int		ft_maxarray(int array[], size_t len);
int		ft_minarray(int array[], size_t len);
int		ft_sum(int array[], size_t len);
int		ft_all(int array[], size_t len);
int		ft_any(int array[], size_t len);

size_t	ft_arrylen(void *array[]);

#endif
