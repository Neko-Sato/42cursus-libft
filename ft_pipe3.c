/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:30:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/22 08:30:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pipe3(int *reader, int *writer)
{
	int	ret;
	int	fd[2];

	ret = pipe(fd);
	if (!ret)
	{
		*reader = fd[0];
		*writer = fd[1];
	}
	return (ret);
}
