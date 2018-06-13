/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/16 20:21:01 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_att(char *fmt, t_arg *data)
{
	if (*fmt && *fmt == '#')
		data->flag |= F_HASH;
	else if (*fmt && *fmt == ' ')
		data->flag |= F_SPACE;
	else if (*fmt && *fmt == '0')
		data->flag |= F_ZERO;
	else if (*fmt && *fmt == '-')
		data->flag |= F_MINUS;
	else if (*fmt && *fmt == '+')
		data->flag |= F_PLUS;
	return (1);
}

int			get_mod(char *fmt, t_arg *data)
{
	int		j;

	j = 0;
	if (fmt[j] && fmt[j] == 'l')
		data->flag |= (fmt[j + 1] && fmt[j + 1] == 'l') ? F_LL : F_L;
	else if (fmt[j] && fmt[j] == 'h')
		data->flag |= (fmt[j + 1] && fmt[j + 1] == 'h') ? F_HH : F_H;
	else if (fmt[j] && fmt[j] == 'j')
		data->flag |= F_J;
	else if (fmt[j] && fmt[j] == 'z')
		data->flag |= F_Z;
	if ((fmt[j] == 'l' && fmt[j + 1] && fmt[j + 1] == 'l') || (fmt[j] == 'h' &&
		fmt[j + 1] && fmt[j + 1] == 'h'))
		j++;
	return (j + 1);
}

int			get_width(char *fmt, t_arg *data)
{
	data->larg = ft_atoi(fmt);
	return (ft_ilen_base(data->larg, 10));
}

int			get_pre(char *fmt, t_arg *data)
{
	if (fmt[1] && ft_isdigit(fmt[1]))
	{
		if (fmt[1] == '0')
		{
			data->preci = 0;
			return (2);
		}
		data->preci = ft_atoi(fmt + 1);
		return (ft_ilen_base(data->preci, 10) + 1);
	}
	data->preci = 0;
	return (1);
}
