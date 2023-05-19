/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/19 11:15:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*_dst;

	_dst = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (_dst);
}
