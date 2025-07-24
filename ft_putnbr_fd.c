/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:27:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/24 22:27:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[11];
	int				i;
	unsigned int	un;

	i = sizeof(buf);
	if (n < 0)
		un = -n;
	else
		un = n;
	while (1)
	{
		buf[--i] = '0' + un % 10;
		un /= 10;
		if (!un)
			break ;
	}
	if (n < 0)
		buf[--i] = '-';
	write(fd, &buf[i], sizeof(buf) - i);
}
