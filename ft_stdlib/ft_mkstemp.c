/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkstemp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 06:40:09 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/10 06:45:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ft_stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int	ft_mkstemp(char *template)
{
	ft_mktemp(template);
	return (open(template, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR));
}
