/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__write_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:04:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 12:29:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <unistd.h>

ssize_t	ft__write_fd(const void *buf, size_t n, void *arg)
{
	return (write(*(int *)arg, buf, n));
}
