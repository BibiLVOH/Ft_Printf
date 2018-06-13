/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/18 11:36:30 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg_with_zero(t_arg *data)
{
	if (data->arg[0] != '0')
	{
		data->arg = ft_x_join(data->larg - data->size - 2, '0', data->size,
		data);
		data->arg = ft_x_join(1, 'x', data->size, data);
		data->arg = ft_x_join(1, '0', data->size, data);
	}
	else
		data->arg = ft_x_join(data->larg - data->size, '0', data->size,
		data);
	return (data->arg);
}

static char		*modif_larg_with_minus(t_arg *data)
{
	if (data->arg[0] != '0')
	{
		data->arg = ft_x_join(1, 'x', data->size, data);
		data->arg = ft_x_join(1, '0', data->size, data);
		data->arg = ft_join_x(data->larg - data->size, ' ', data->size,
		data);
	}
	else
		data->arg = ft_join_x(data->larg - data->size, ' ', data->size,
		data);
	return (data->arg);
}

static char		*modify_conv(uintmax_t i, t_arg *data)
{
	if (data->preci == 0 && i == 0)
	{
		ft_strdel(&data->arg);
		data->arg = ft_strdup("");
		data->size = 0;
	}
	if (data->preci > data->size)
		data->arg = ft_x_join(data->preci - data->size, '0', data->size, data);
	data->arg = ft_x_join(1, 'x', data->size, data);
	data->arg = ft_x_join(1, '0', data->size, data);
	if (data->larg > data->size && data->flag & F_ZERO)
		data->arg = modif_larg_with_zero(data);
	else if (data->larg > data->size && data->flag & F_MINUS)
		data->arg = modif_larg_with_minus(data);
	else if (data->larg > data->size)
		data->arg = ft_x_join(data->larg - data->size, ' ', data->size, data);
	return (data->arg);
}

int				conv_p(t_arg *data, va_list ap)
{
	uintmax_t	i;

	i = va_arg(ap, unsigned long);
	data->arg = ft_tolower(ft_utoa_base(i, 16));
	data->size = ft_strlen(data->arg);
	data->arg = modify_conv(i, data);
	data->buf = ft_strjoin(data->buf, data->arg, data);
	return (data->size);
}
