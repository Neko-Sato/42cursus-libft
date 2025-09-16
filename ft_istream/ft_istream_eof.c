/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_eof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:01:47 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/17 02:40:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>

int	ft_istream_eof(const t_istream *is)
{
	return (!!(is->_flags & _ISTREAM_FLAGS_EOF));
}
