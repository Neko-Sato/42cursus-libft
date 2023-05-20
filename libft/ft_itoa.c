// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_itoa.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/20 20:58:22 by hshimizu          #+#    #+#             */
// /*   Updated: 2023/05/20 21:31:04 by hshimizu         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// static size_t	len(int n)
// {
// 	size_t	count;

// 	count = 0;
// 	while (n)
// 		n /= 10 + 0 * count++;
// 	return (count);
// }

// char			*ft_itoa(int n);
// {
// 	char *result;
// 	char *_result;
// 	size_t len;

// 	if (!n)
// 		return (ft_strdup("0"));
// 	while (n)
// 		result = (char *)malloc((ft_abs(nbr) + (nbr < 0) + 1) * sizeof(char));
// 	_result = result;
// 	if (n < 0)
// 		*result++ = '-';
// 	nbr = ft_abs(nbr);
// 	if (nbr == 0)
// 		*(str++) = base[0];
// 	return (result);
// }