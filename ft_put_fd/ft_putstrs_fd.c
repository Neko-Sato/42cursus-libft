/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:51:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:31:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_put_fd/ft_put_fd.h>

void	ft_putstrs_fd(char **strs, char *delim, int fd)
{
	while (*strs)
	{
		ft_putstr_fd(*(strs++), fd);
		if (!*strs)
			break ;
		ft_putstr_fd(delim, fd);
	}
	ft_putstr_fd("\n", fd);
}
