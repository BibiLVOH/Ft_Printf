/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchen <mchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:27:23 by mchen             #+#    #+#             */
/*   Updated: 2018/05/17 23:32:51 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_len(char *format, va_list ap, t_arg *data)
{
	size_t		i;

	data->len = 0;
	data->size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			data->size = i;
			data->buf = ft_strjoin(data->buf, ft_strndup(format, i), data);
			data->len += data->size;
			format += i + 1;
			i = parse_index(format, ap, data);
			data->size = 0;
			format += i;
			i = 0;
		}
		else
			i++;
	}
	data->size = i;
	data->buf = ft_strjoin(data->buf, ft_strndup(format, i), data);
	data->len += data->size;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_arg		data;

	va_start(ap, format);
	data.buf = ft_strdup("");
	get_len((char *)format, ap, &data);
	va_end(ap);
	write(1, data.buf, data.len);
	ft_strdel(&data.buf);
	return (data.len);
}
