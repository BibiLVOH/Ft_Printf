/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:00:49 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/16 20:23:09 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnstr(char *str, int n)
{
	if (n <= 0)
		return ;
	if (n < (int)ft_strlen(str))
		write(1, str, n);
	else
		write(1, str, ft_strlen(str));
}

void	ft_put_nb_max(intmax_t nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar((nb % 10) + '0');
	if (nb >= 10)
	{
		ft_put_nb_max(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_put_u_nb_max(uintmax_t nb)
{
	if (nb < 10)
		ft_putchar((nb % 10) + '0');
	if (nb >= 10)
	{
		ft_put_u_nb_max(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}
