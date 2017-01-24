/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 13:48:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void ft_putpercent(char *str)
{
	ft_putchar('%');
}

int	ft_putpercent_f(char *s, va_list *p)
{
	char *arg;
	int nb;
	int diff;
	int	check_type;


	diff = 0;
	nb = 0;
	check_type = 1;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_flag_str(s, (void*)arg, check_type);
	ft_handle_str(s, arg, check_type);
	ft_size_chain_str(s, nb, diff);
	ft_putpercent(arg);
	ft_size_chain_str_plus(s, nb, diff);
	return (0);
}
