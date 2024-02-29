/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortstrarry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:28:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/29 20:37:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>
#include <ft_stdlib.h>
#include <ft_utils.h>

void	ft_sortstrarry(char *arry[])
{
	size_t	len;

	len = ft_arrylen((void *)arry);
	ft_qsort(arry, len, sizeof(char *), ft_strptrcmp);
}
