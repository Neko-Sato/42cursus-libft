/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:23:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/13 18:19:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_put_fd.h>
#include <ft_stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[12];
	int				i;
	unsigned int	m;

	i = 12;
	buf[--i] = '\0';
	m = ft_abs(n);
	while (1)
	{
		buf[--i] = '0' + m % 10;
		m /= 10;
		if (!m)
			break ;
	}
	if (n < 0)
		buf[--i] = '-';
	ft_putstr_fd(&buf[i], fd);
}
