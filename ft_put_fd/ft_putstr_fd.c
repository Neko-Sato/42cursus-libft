/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:16:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 17:21:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = write(fd, s, ft_strlen(s));
	(void)size;
}
