/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:23:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/19 11:04:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(const unsigned char *)s1++ != *(const unsigned char *)s2++)
			return (*--(const unsigned char *)s1 - *--(const unsigned char *)s2)
	}
	return (0);
}