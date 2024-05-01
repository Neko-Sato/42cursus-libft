/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfilename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:11:39 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/02 05:00:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pathlib.h>
#include <ft_string.h>

char	*ft_getfilename(char *path)
{
	char	*filename;

	filename = ft_strrchr(path, PATH_SEPARATE);
	if (filename)
		filename++;
	else
		filename = path;
	return (ft_strdup(filename));
}
