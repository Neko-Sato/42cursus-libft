/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:06:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 13:33:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sgin;
	int	result;

	sgin = 1;
	result = 0;
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sgin *= -1;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (sgin * result);
}
