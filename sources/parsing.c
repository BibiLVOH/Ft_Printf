/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 17:27:49 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_att(t_arg *data)
{
	int		i;

	i = 0;
	if (data->flag & F_L)
		i++;
	if (data->flag & F_LL)
		i++;
	if (data->flag & F_H)
		i++;
	if (data->flag & F_HH)
		i++;
	if (data->flag & F_J)
		i++;
	if (data->flag & F_Z)
		i++;
	return (i);
}

static void		last_check(char conv, t_arg *data)
{
	int		i;

	i = check_att(data);
	if (i >= 2)
	{
		data->flag &= ~F_L;
		data->flag &= ~F_LL;
		data->flag &= ~F_H;
		data->flag &= ~F_HH;
		data->flag &= ~F_Z;
		data->flag |= F_J;
	}
	if ((data->preci >= 0 && conv != 'c' && conv != 'C' && conv != 's' &&
	conv != 'S') || data->flag & F_MINUS)
		data->flag &= ~F_ZERO;
	if (data->flag & F_SPACE && data->flag & F_PLUS)
		data->flag &= ~F_SPACE;
}

static int		loop_parse(char *fmt, int i, t_arg *data)
{
	if (ft_strchr(ATT_LST, fmt[i]))
		i += get_att(fmt + i, data);
	else if (ft_strchr(MOD_LST, fmt[i]))
		i += get_mod(fmt + i, data);
	else if (ft_isdigit(fmt[i]) && fmt[i] != '0')
		i += get_width(fmt + i, data);
	else if (fmt[i] == '.')
		i += get_pre(fmt + i, data);
	return (i);
}

int				parse_index(char *fmt, va_list ap, t_arg *data)
{
	int		i;

	i = 0;
	data->flag = 0;
	data->preci = -1;
	data->larg = 0;
	if (fmt[i] == '%')
	{
		data->arg = ft_strdup("%");
		data->size = 1;
		data->buf = ft_strjoin(data->buf, data->arg, data);
		data->len += 1;
		return (1);
	}
	while (fmt[i] && (ft_strchr(ALL_CHAR, fmt[i])))
		i = loop_parse(fmt, i, data);
	if (fmt[i] && ft_strchr(CONV_LST, fmt[i]))
	{
		last_check(fmt[i], data);
		data->len += convert(fmt + i, ap, data);
		i++;
	}
	else if (fmt[i])
		i += conv_none(fmt[i], data);
	return (i);
}
