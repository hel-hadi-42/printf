/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:59:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/26 18:36:04 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int	ft_size_chain_nbr_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s, siz->nbr) == 1)
		siz->d = '0';
	if (ft_check_zero(s, siz->nbr) == 0)
		siz->d = ' ';
	if (!siz->nbr_prec)
		siz->len = siz->nbr - t_arg - diff;
	else if (!siz->nbr)
		siz->len = siz->nbr_prec - t_arg;
	else if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr == siz->nbr_prec && (ft_check_space(s) || ft_check_more(s)))
		{
			diff = diff - 1;
		}
		if (siz->nbr >= siz->nbr_prec)
			siz->len = siz->nbr - t_arg - diff;
		else if (siz->nbr < siz->nbr_prec)
			siz->len = siz->nbr_prec - t_arg;
		siz->ecart =  siz->nbr - siz->nbr_prec -  diff;
		siz->d = '0';
		siz->e = ' ';
	}
}

int		ft_size_chain_nbr(char *s, int t_arg, int diff, int arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_more(s) && (!ft_check_point(s)) && ft_putplus_nbr(s, arg)
	&& (t_arg > siz.nbr || ft_check_zero(s, siz.nbr)))
	{
		ft_putchar('+');
		siz.val++;
		siz.flag = 1;
	}
	if (ft_check_more(s) && siz.nbr && siz.nbr_prec
	&& (siz.nbr_prec > siz.nbr || siz.nbr_prec == siz.nbr))
	{
		ft_putchar('+');
		siz.val++;
		siz.flag = 1;
	}
	if (ft_check_space(s) && (!ft_check_more(s)) && ft_putplus_nbr(s, arg))
	{
		ft_putchar(' ');
		siz.val++;
	}
	if (ft_check_less(s) && (!ft_check_point(s)))
		return (siz.val);
	ft_size_chain_nbr_bis(&siz, s, t_arg, diff);
	while (siz.i < siz.len)
	{
		if (siz.i < siz.ecart)
		{
			ft_putchar(siz.e);
			siz.val++;
		}
		else if (siz.i >= siz.ecart)
		{
			if (!siz.flag && ft_check_more(s) && ft_putplus_nbr(s, arg)
			 && siz.nbr_prec < siz.nbr && siz.nbr_prec)
			{
				ft_putchar('+');
				siz.val++;
				siz.flag = 1;
			}
			siz .val++;
			ft_putchar(siz.d);
		}
		siz.i++;
	}
	if (!siz.flag && ft_check_more(s) && ft_putplus_nbr(s, arg))
	{
		ft_putchar('+');
		siz.val++;
		siz.flag = 1;
	}
	return (siz.val);
}

int	ft_size_chain_nbr_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	if (ft_check_less(s) == 0 || ft_check_point(s) == 1)
		return (0);
	siz.nbr = ft_record_chain(s);
	siz.i = 0;
	if (t_arg > siz.nbr)
		return (0);
	siz.len = siz.nbr - t_arg - diff;
	if (ft_check_space(s) == 1 && siz.nbr && ft_check_more(s) == 0)
		siz.len -= 1;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.val++;
		siz.i++;
	}
	return (siz.val);
}
