/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:23:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:47:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_put_fd.h>
#include <ft_stdlib.h>

static size_t	ft_itoalen(int n)
{
	size_t			len;
	unsigned int	m;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	m = ft_abs(n);
	while (m)
		m /= 10 + 0 * len++;
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[12];
	int				i;
	unsigned int	m;

	i = ft_itoalen(n);
	buf[i--] = '\0';
	m = ft_abs(n);
	while (1)
	{
		buf[i--] = '0' + m % 10;
		m /= 10;
		if (!m)
			break ;
	}
	if (n < 0)
		buf[i--] = '-';
	ft_putstr_fd(buf, fd);
}
