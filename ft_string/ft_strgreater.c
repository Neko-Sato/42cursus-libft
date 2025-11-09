/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgreater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:33:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:36:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

int	ft_strgreater(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) > 0);
}
