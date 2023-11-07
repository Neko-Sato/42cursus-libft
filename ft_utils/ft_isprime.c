/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:17:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/07 20:23:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	newtons_method_sqrt(double n, unsigned int precision);

int	ft_isprime(int n)
{
	int	i;
	int	end;

	if (n < 2)
		return (0);
	end = newtons_method_sqrt(n, 20);
	i = 2;
	while (i <= end)
		if (!(n % i++))
			return (0);
	return (1);
}
static double	newtons_method_sqrt(double n, unsigned int precision)
{
	double	result;

	result = n / 2;
	while (precision--)
		result = result - result / 2 + n / (2 * result);
	return (result);
}
