/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 15:44:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strwclen(wchar_t arg)
{
	int nb;

	nb = 0;
	if (arg <= 127)
		nb = 1;
	else if (arg <= 2047)
		nb = 2;
	else if (arg <= 65535)
		nb = 3;
	else if (arg <= 1114111)
		nb = 4;
	return (nb);
}

void	ft_putchar_maj(wchar_t c)
{
	wchar_t d;
	wchar_t e;

	d = c;
	e = c;
	if (c <= 127)
		d = 1;
	else if (c <= 2047)
	{
		d =  (d >> 6 | 0xC0);
		c = ((c & 0x3F) | 0x80);
		c = (c << 8 | d);
		d = 2;
	}
	else if (c <= 65535)
	{
		c = (((c & 0x3F) | 0x80) << 16);
		d = ((((d & 0xFC0) >> 6) | 0x80) << 8);
		e = ((e >> 12) | 0xE0);
		c = ((e | d) | c);
		d = 3;
	}
	else if (c <= 1114111)
	{
		c = (((c & 0x3F) | 0x80) << 24);
		d = ((((d & 0xFC0) >> 6) | 0x80) << 16);
		e = (((e >> 12) | 0x80) << 8);
		c = (((c | d) | e) | 0xF0);
		d = 4;
	}
	write(1, &c, d);
}

int	ft_putchar_maj_f(char *s, va_list *p)
{
	wchar_t arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, wchar_t);
	ptr.nb = ft_strwclen(arg);
	ptr.check_type = 1;
	ptr.diff = ft_char_size(s, ptr.check_type);
	ft_handle_char(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_char(s, ptr.nb, ptr.diff);
	ft_putchar_maj(arg);
	ptr.val = ptr.val + ft_size_chain_char_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
