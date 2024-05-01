/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 05:01:03 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/02 05:13:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_startwith(char *str, char *prefix)
{
	while (*str && *prefix)
		if (*str++ != *prefix++)
			return (0);
	return (!*prefix);
}
