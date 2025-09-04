/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__read_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:43:31 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/04 23:37:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <unistd.h>

ssize_t	ft__read_fd(void *buf, size_t n, int *fd)
{
	return (read(*fd, buf, n));
}
