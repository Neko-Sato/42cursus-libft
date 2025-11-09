/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:30:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:31:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

int	ft_strequal(const char *s1, const char *s2)
{
	return (!ft_strcmp(s1, s2));
}
