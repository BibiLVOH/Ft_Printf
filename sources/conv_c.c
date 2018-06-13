/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/18 09:37:00 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modify_conv(t_arg *data)
{
	if (data->larg > 1)
	{
		if (data->flag & F_MINUS)
			data->arg = ft_join_x(data->larg - 1, ' ', data->size, data);
		else if (data->flag & F_ZERO)
			data->arg = ft_x_join(data->larg - 1, '0', data->size, data);
		else
			data->arg = ft_x_join(data->larg - 1, ' ', data->size, data);
	}
	return (data->arg);
}

int				conv_c(t_arg *data, va_list ap)
{
	char		c;

	c = va_arg(ap, int);
	if (c == '\0')
		data->arg = ft_strdup("");
	else
	{
		data->arg = ft_strnew(2);
		data->arg[0] = c;
		data->arg[1] = '\0';
	}
	data->size = 1;
	data->arg = modify_conv(data);
	data->buf = ft_strjoin(data->buf, data->arg, data);
	return (data->size);
}

int				conv_none(char let, t_arg *data)
{
	data->arg = ft_strnew(2);
	data->arg[0] = let;
	data->arg[1] = '\0';
	data->size = 1;
	data->arg = modify_conv(data);
	data->buf = ft_strjoin(data->buf, data->arg, data);
	data->len += data->size;
	return (1);
}
