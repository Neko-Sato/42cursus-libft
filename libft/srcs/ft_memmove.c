/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/16 22:43:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, int n)
{
	void	*_dst;
	int		direction;

	direction = 1 - 2 * (dst < src);
	if (direction < 0)
	{
		dst += n;
		src += n;
	}
	while (n--)
	{
		*(char *)dst++ = *(char *)src;
		dst += direction;
		src += direction;
	}
	return (_dst);
}

#include <stdio.h>

int	main(void)
{
	char str[] = "abcdefghijklmnopqrstu";

	printf("%s\n", str);

	ft_memmove(str + 5, str, 10); /* 重複エリアのコピー */

	printf("%s\n", str);

	return (0);
}