/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:20:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 08:21:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>
#include <stddef.h>

/*
	Imitate a switch statement.
	Tell how many cases in the switch statement by get_case_num.
	case_max is the number of cases.
	case_fns indicates each case, return -1 for errors and 1 for breaks.
*/

int	ft_switchcase(t_switchcase *args, void *expression)
{
	size_t	i;
	int		ret;

	i = args->get_case_num(expression);
	while (i < args->case_max)
	{
		ret = args->case_fns[i](args->args);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			break ;
		i++;
	}
	return (0);
}
