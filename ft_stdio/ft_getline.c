/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:30:05 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 04:56:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <unistd.h>

ssize_t	ft_getline(char **lineptr, size_t *n, t_file *stream)
{
	return (ft_getdelim(lineptr, n, '\n', stream));
}
