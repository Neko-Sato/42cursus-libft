/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:07:18 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/19 23:58:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static void	move_dir(char *path, char *result);

char	*ft_realpath(const char *path, char *resolved_path)
{
	char	temp[PATH_MAX];
	char	result[PATH_MAX];

	if (!getcwd(result, PATH_MAX))
		return (NULL);
	ft_strlcpy(temp, path, PATH_MAX);
	move_dir(temp, result);
	if (resolved_path)
		return (ft_strcpy(resolved_path, result));
	return (ft_strdup(result));
}

static void	move_dir(char *path, char *result)
{
	char	*temp;

	while (1)
	{
		temp = ft_strsep(&path, "/");
		if (!temp)
			break ;
		if (!ft_strcmp(temp, "."))
			;
		else if (!ft_strcmp(temp, ".."))
		{
			temp = ft_strrchr(result, '/');
			if (temp)
				*temp = '\0';
		}
		else
		{
			if (result[ft_strlen(result) - 1] != '/')
				ft_strlcat(result, "/", PATH_MAX);
			ft_strlcat(result, temp, PATH_MAX);
		}
	}
}
