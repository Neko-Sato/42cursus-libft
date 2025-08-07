/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:46:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 20:12:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saveptr;

	return (ft_strtok_r(str, delim, &saveptr));
}
