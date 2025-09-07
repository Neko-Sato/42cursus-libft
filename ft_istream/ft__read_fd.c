/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__read_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:43:31 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 12:28:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <unistd.h>

ssize_t	ft__read_fd(void *buf, size_t n, void *arg)
{
	return (read(*(int *)arg, buf, n));
}
