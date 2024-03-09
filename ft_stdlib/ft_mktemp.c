/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:42:02 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/10 06:47:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ft_stdlib.h>
#include <ft_string.h>
#include <unistd.h>

#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

static void	set_xxxxxx(char *xxxxxx);

char	*ft_mktemp(char *template)
{
	size_t	len;
	char	*xxxxxx;

	len = ft_strlen(template);
	xxxxxx = &template[len - 6];
	if (!ft_strcmp(xxxxxx, "XXXXXX"))
	{
		while (1)
		{
			set_xxxxxx(xxxxxx);
			if (access(template, F_OK))
				break ;
		}
	}
	else
		template[0] = '\0';
	return (template);
}

static void	set_xxxxxx(char *xxxxxx)
{
	int	dev_random;
	int	i;

	dev_random = open("/dev/random", O_RDONLY);
	if (dev_random)
	{
		i = read(dev_random, xxxxxx, sizeof(char [6]));
		close(dev_random);
	}
	else
	{
		i = 0;
		while (i < 6)
			xxxxxx[i++] = ft_random();
	}
	i = 0;
	while (i < 6)
	{
		xxxxxx[i] = LETTERS[xxxxxx[i] % (sizeof(LETTERS) - 1)];
		i++;
	}
}
