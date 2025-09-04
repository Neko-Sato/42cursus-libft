/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_getline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:34:10 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/03 17:40:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>

ssize_t	ft_istream_getline(char **lineptr, size_t *n, t_istream *is)
{
	return (ft_istream_getdelim(lineptr, n, is, '\n'));
}
