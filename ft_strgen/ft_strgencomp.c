/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:55 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/27 19:30:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	ft_strgenflush(strgen);
	if (strgen->str)
		ret = strgen->str;
	else
		ret = ft_strdup("");
	strgen->str = NULL;
	strgen->pos = 0;
	return (ret);
}
