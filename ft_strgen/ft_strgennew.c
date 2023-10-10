/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgennew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:49:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:09:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <stdlib.h>

t_strgen	*ft_strgennew(void)
{
	t_strgen	*strgen;

	strgen = (t_strgen *)malloc(sizeof(t_strgen));
	if (!strgen)
		return (NULL);
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (strgen);
}
