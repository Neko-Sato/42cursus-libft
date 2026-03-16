/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:12:18 by hshimizu          #+#    #+#             */
/*   Updated: 2026/03/17 05:19:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_getopt/ft_getopt.h>
#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>
#include <unistd.h>

static inline void	_error(const char *prog, const char *msg, char c)
{
	int			fd;
	t_ostream	os;
	char		buf[1024];

	fd = STDERR_FILENO;
	ft_ostream_init(&os, &(t_ostream_init){buf, sizeof(buf), ft__write_fd, &fd,
		OSTREAM_FULLBUF});
	ft_ostream_write(&os, prog, ft_strlen(prog));
	ft_ostream_write(&os, ": ", 2);
	ft_ostream_write(&os, msg, ft_strlen(msg));
	ft_ostream_write(&os, ": ", 2);
	ft_ostream_write(&os, &c, 1);
	ft_ostream_write(&os, "\n", 1);
	ft_ostream_destroy(&os);
}

static inline int	_unrecognized(const char *prog, const char *optstring,
		t_getopt *opt, char c)
{
	opt->optopt = c;
	if (optstring[0] != ':' && opt->opterr)
		_error(prog, "unrecognized option", c);
	return ('?');
}

static inline int	_noargument(const char *prog, const char *optstring,
		t_getopt *opt, char c)
{
	opt->optopt = c;
	if (optstring[0] == ':')
		return (':');
	if (opt->opterr)
		_error(prog, "option requires an argument", c);
	return ('?');
}

static inline int	_internal(int argc, char *const argv[],
		const char *optstring, t_getopt *opt)
{
	char	c;
	char	*p;

	c = argv[opt->optind][opt->_optpos++];
	if (!argv[opt->optind][opt->_optpos])
	{
		opt->optind++;
		opt->_optpos = 0;
	}
	p = ft_strchr(optstring, c);
	if (!p || c == ':')
		return (_unrecognized(argv[0], optstring, opt, c));
	if (p[1] == ':')
	{
		if (opt->optind < argc)
		{
			opt->optarg = &argv[opt->optind++][opt->_optpos];
			opt->_optpos = 0;
		}
		else
			return (_noargument(argv[0], optstring, opt, c));
	}
	return (c);
}

int	ft_getopt(int argc, char *const argv[], const char *optstring,
		t_getopt *opt)
{
	if (!opt->optind)
	{
		opt->optind = 1;
		opt->_optpos = 0;
	}
	if (opt->optind >= argc || !argv[opt->optind])
		return (-1);
	if (argv[opt->optind][0] != '-')
		return (-1);
	if (!argv[opt->optind][1])
		return (-1);
	if (argv[opt->optind][1] == '-' && !argv[opt->optind][2])
		return (opt->optind++, -1);
	if (!opt->_optpos)
		opt->_optpos++;
	return (_internal(argc, argv, optstring, opt));
}
