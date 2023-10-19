/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:34:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 23:09:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	*ft_2darraynew(size_t size, size_t width, size_t height)
{
	return (ft_ndarraynew(size, (size_t []){width, height}, 2));
}
