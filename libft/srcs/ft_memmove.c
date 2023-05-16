/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/16 23:13:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, int n)
{
	void	*_dst;
	int		direction;

	direction = 1;
	if (dst > src)
	{
		direction = -1;
		dst += n - 1;
		src += n - 1;
	}
	while (n--)
	{
		*(char *)dst = *(char *)src;
		dst += direction;
		src += direction;
	}
	return (_dst);
}
