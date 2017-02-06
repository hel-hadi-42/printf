/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 16:17:53 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_letter(char *s, char c)
{
	int i;
	int auth;

	i = 0;
	auth = 0;
	while (s[i])
	{
		if (s[i] == c)
			auth++;
		i++;
	}
	if (auth > 1)
		return (1);
	return (0);
}

int		ft_check_letter_o(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'O')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_return_chain(char *s)
{
	int		i;
	char	*s1;

	i = 1;
	while (s[i] && (!check_ptr2(s[i])))
		i++;
	if (check_ptr(s[i], s[i + 1], s[i + 2]))
	{
		s1 = ft_strsub(s, 1, i);
		return (s1);
	}
	return (NULL);
}

int		ft_check_spec(char *s)
{
	int i;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1], s[i + 2]) == 0)
		i++;
	if (check_ptr(s[i], s[i + 1], s[i + 2]))
		return (check_ptr(s[i], s[i + 1], s[i + 2]));
	return (0);
}
