/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 18:19:29 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int	diff;
	int	check_type;

	check_type = 1;
	arg = va_arg(*p, int);
	nb = 1;
	diff = ft_char_size(s, check_type);
	ft_handle_char(s, check_type);
	ft_size_chain_char(s, nb, diff);
	ft_putchar(arg);
	ft_size_chain_char_plus(s, nb, diff);
	return (0);
}