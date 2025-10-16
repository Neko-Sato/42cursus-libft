/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:38:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 18:18:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <stdlib.h>

void	ft_ostream_destroy(t_ostream *os)
{
	ft_ostream_flush(os);
	if (os->_flags & _OSTREAM_OWNS_BUF)
		free(os->_buf);
}
