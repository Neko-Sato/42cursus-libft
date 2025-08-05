/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 07:10:02 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:13:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memswap(void *a, void *b, size_t n)
{
	unsigned char	tmp;
	unsigned char	*ua;
	unsigned char	*ub;

	ua = a;
	ub = b;
	while (n)
	{
		tmp = *ua;
		*ua = *ub;
		*ub = tmp;
		(void)(n--, ua++, ub++);
	}
}
