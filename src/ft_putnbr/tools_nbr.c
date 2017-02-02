/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:07:07 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 19:06:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_short2(signed char n)
{
	int nb;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_short2(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_short(short int n)
{
	 int nb;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_short(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_max(intmax_t n)
{
	size_t nb;

	nb = n;
	if (!nb)
		nb = nb * (-1);
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_max(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_size(size_t n)
{
	size_t nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_size(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_long(int long n)
{

	int long nb;
	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_long(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_long2(long long n)
{

	long long nb;
	nb = n;
	if ((long long)nb < -9223372036854775807)
		ft_putstr("9223372036854775808");
	else
	{
		if (nb < 0)
			nb = nb * (-1);
		if (nb >= 0 && nb <= 9)
			ft_putchar(nb + 48);
		if (nb > 9)
		{
			ft_putnbr_long2(nb / 10);
			ft_putchar((nb % 10) + 48);
		}
	}
}