/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__intprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:32:23 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 16:14:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>

static void	_numeric(unsigned long long n, t__iniprint_var *var,
		unsigned int base, int isupper)
{
	while (n)
	{
		*--var->pos = "0123456789abcdef0123456789ABCDEF"[n
			% base | (isupper << 4)];
		n /= base;
	}
}

static void	_internal(unsigned long long n, const t__iniprint_args *args,
		t__iniprint_var *var)
{
	var->prec = 1;
	if (args->prec != -1)
		var->prec = args->prec;
	if (var->prec < var->digit)
		var->prec = var->digit;
	var->size = var->prec;
	if (var->neg
		|| (args->flags & (_INTPRINT_FLAG_MARK_POS | _INTPRINT_FLAG_PAD_POS)))
		var->size++;
	if (n != 0 && args->flags & _INTPRINT_FLAG_ALT_FORM)
	{
		if (args->base == 16)
			var->size += 2;
		else if (args->base == 8)
			var->size++;
	}
	var->pad = 0;
	if (args->width != -1 && var->size < (size_t)args->width)
		var->pad = args->width - var->size;
	if (!(args->flags & _INTPRINT_FLAG_LEFT_ADJ)
		&& args->flags & _INTPRINT_FLAG_ZERO_PAD)
	{
		var->prec += var->pad;
		var->pad = 0;
	}
}

static inline size_t	_out(t_ostream *os, unsigned long long n,
		const t__iniprint_args *args, t__iniprint_var *var)
{
	size_t	ret;

	ret = 0;
	if (!(args->flags & _INTPRINT_FLAG_LEFT_ADJ))
		while (var->pad)
			ret += (var->pad--, ft_ostream_write(os, " ", 1));
	if (var->neg)
		ret += ft_ostream_write(os, "-", 1);
	else if (args->flags & _INTPRINT_FLAG_MARK_POS)
		ret += ft_ostream_write(os, "+", 1);
	else if (args->flags & _INTPRINT_FLAG_PAD_POS)
		ret += ft_ostream_write(os, " ", 1);
	if ((args->base == 16 || args->base == 8) && n != 0
		&& args->flags & _INTPRINT_FLAG_ALT_FORM)
		ret += ft_ostream_write(os,
				&"0x0X"[!!(args->flags & _INTPRINT_FLAG_UPPER) << 1], 1
				<< (args->base == 16));
	while (var->prec > var->digit)
		ret += (var->prec--, ft_ostream_write(os, "0", 1));
	ret += ft_ostream_write(os, var->pos, var->digit);
	if (args->flags & _INTPRINT_FLAG_LEFT_ADJ)
		while (var->pad)
			ret += (var->pad--, ft_ostream_write(os, " ", 1));
	return (ret);
}

size_t	ft__intprint(t_ostream *os, unsigned long long n,
		const t__iniprint_args *args)
{
	char			buf[1024];
	t__iniprint_var	var;

	var.neg = args->flags & _INTPRINT_FLAG_SIGNED && (long long)n < 0;
	if (var.neg)
		n = -(long long)n;
	var.pos = &buf[sizeof(buf)];
	_numeric(n, &var, args->base, !!(args->flags & _INTPRINT_FLAG_UPPER));
	var.digit = &buf[sizeof(buf)] - var.pos;
	_internal(n, args, &var);
	return (_out(os, n, args, &var));
}
