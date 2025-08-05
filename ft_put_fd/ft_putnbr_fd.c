/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:27:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 19:13:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[11];
	char			*tmp;
	unsigned int	un;

	tmp = &buf[11];
	if (n < 0)
		un = -n;
	else
		un = n;
	while (1)
	{
		*--tmp = '0' + un % 10;
		un /= 10;
		if (!un)
			break ;
	}
	if (n < 0)
		*--tmp = '-';
	write(fd, tmp, &buf[11] - tmp);
}
