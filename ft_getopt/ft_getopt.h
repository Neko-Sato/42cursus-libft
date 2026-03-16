/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:10:23 by hshimizu          #+#    #+#             */
/*   Updated: 2026/03/17 04:00:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

typedef struct s_getopt
{
	int		optind;
	char	*optarg;
	int		opterr;
	int		optopt;
	int		_optpos;
}			t_getopt;

int			ft_getopt(int argc, char *const argv[],
				const char *optstring, t_getopt *opt);

#endif
