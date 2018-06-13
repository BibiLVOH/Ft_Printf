/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 23:01:23 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_atoi(const char *str)
{
	int		neg;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
}

char		*ft_itoa_base(intmax_t n, int base)
{
	char	*res;
	int		len;
	char	buf[17];

	res = NULL;
	ft_strncpy(buf, "0123456789ABCDEF", 16);
	len = ft_ilen_base(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = buf[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

int			ft_ilen_base(intmax_t n, int base)
{
	int		cpt;

	cpt = 0;
	if (n == 0)
		cpt = 1;
	while (n)
	{
		cpt++;
		n = n / base;
	}
	return (cpt);
}

char		*ft_utoa_base(uintmax_t n, int base)
{
	char	*res;
	int		len;
	char	buf[17];

	res = NULL;
	ft_strncpy(buf, "0123456789ABCDEF", 16);
	len = ft_ulen_base(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len && n)
	{
		res[len - 1] = buf[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}

int			ft_ulen_base(uintmax_t n, int base)
{
	int		cpt;

	cpt = 0;
	if (n == 0)
		cpt = 1;
	while (n)
	{
		cpt++;
		n = n / base;
	}
	return (cpt);
}
