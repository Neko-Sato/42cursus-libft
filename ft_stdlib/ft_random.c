/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 06:10:32 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/16 17:50:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_random(void)
{
	static long	temp;
	char		stack[0];

	temp += (long)&stack;
	temp ^= temp << 13;
	temp ^= temp >> 17;
	temp ^= temp << 5;
	return (temp);
}
