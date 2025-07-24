/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:05:38 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/24 22:19:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_LOCAL_LIBFT
# include "libft.h"
#else
# include <libft.h>
#endif

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
