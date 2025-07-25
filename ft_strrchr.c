/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:17:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/25 18:17:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (1)
	{
		if (*s == (char)c)
			ret = s;
		if (!*s)
			break ;
		s++;
	}
	return ((char *)ret);
}

/*
int	main(void)
{
	const char	*s = "tripouille";
	int			c;

	c = 0;
	printf("strrchr = %s\n", strrchr(s, c));
	printf("ft_strrchr = %s\n", ft_strrchr(s, c));
	return (0);
}
*/
