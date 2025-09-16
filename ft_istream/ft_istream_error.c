/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:01:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/17 02:40:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>

int	ft_istream_error(const t_istream *is)
{
	return (!!(is->_flags & _ISTREAM_FLAGS_ERROR));
}
