/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarry_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:49:02 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/28 22:24:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_put_fd.h>

void	ft_putstrarry_fd(char *ss[], char *delimiter, int fd)
{
	if (!ss || !*ss)
		return ;
	while (1)
	{
		ft_putstr_fd(*ss++, fd);
		if (!*ss)
			break ;
		if (delimiter)
			ft_putstr_fd(delimiter, fd);
		else
			ft_putstr_fd("\n", fd);
	}
	if (delimiter && *delimiter != '\n')
		ft_putstr_fd("\n", fd);
}
