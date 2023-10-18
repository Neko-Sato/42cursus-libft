/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smalloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:41:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/18 19:44:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SMALLOC_H
# define FT_SMALLOC_H

# include <stddef.h>

size_t	ft_ssizeof(void *ptr);

void	*ft_smalloc(size_t size);
void	ft_sfree(void *ptr);
void	*ft_scalloc(size_t count, size_t size);
void	*ft_srealloc(void *ptr, size_t size);

#endif