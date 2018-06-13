/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 16:59:27 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*modif_larg(t_arg *data)
{
	if (data->flag & F_ZERO)
		data->arg = ft_x_join(data->larg - data->size, '0', data->size, data);
	else if (data->flag & F_MINUS)
		data->arg = ft_join_x(data->larg - data->size, ' ', data->size, data);
	else
		data->arg = ft_x_join(data->larg - data->size, ' ', data->size, data);
	return (data->arg);
}

static char		*modif_preci(t_arg *data)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strndup(data->arg, data->preci);
	data->size = data->preci;
	ft_strdel(&data->arg);
	return (tmp);
}

static char		*modify_conv(t_arg *data)
{
	if (data->preci >= 0 && data->preci < data->size)
		data->arg = modif_preci(data);
	if (data->larg > data->size)
		data->arg = modif_larg(data);
	return (data->arg);
}

int				conv_s(t_arg *data, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		data->arg = ft_strdup("(null)");
	else
		data->arg = ft_strdup(s);
	data->size = ft_strlen(data->arg);
	data->arg = modify_conv(data);
	data->buf = ft_strjoin(data->buf, data->arg, data);
	return (data->size);
}
