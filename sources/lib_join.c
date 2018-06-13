/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:08:08 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 16:44:10 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char *s1, char *s2, t_arg *data)
{
	char	*res;

	res = NULL;
	if (!(res = ft_strnew(data->len + data->size + 1)))
		return (NULL);
	ft_strncpy(res, s1, data->len);
	ft_strncat(res, s2, data->len, data->size);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (res);
}

char	*ft_x_join(int n, char c, int size, t_arg *data)
{
	char	*res;
	char	*add;
	int		i;

	i = 0;
	res = NULL;
	data->size += n;
	if (!(add = (char *)malloc(sizeof(*add) * (n + 1))))
		return (NULL);
	while (n > 0)
	{
		add[i++] = c;
		n--;
	}
	add[i] = '\0';
	if (!(res = ft_strnew(data->size + 1)))
		return (NULL);
	ft_strncpy(res, add, ft_strlen((char *)add));
	ft_strncat(res, data->arg, ft_strlen((char *)add), size);
	ft_strdel(&data->arg);
	ft_strdel(&add);
	return (res);
}

char	*ft_join_x(int n, char c, int size, t_arg *data)
{
	char	*res;
	char	*add;
	int		i;

	i = 0;
	res = NULL;
	data->size += n;
	if (!(add = (char *)malloc(sizeof(*add) * (n + 1))))
		return (NULL);
	while (n > 0)
	{
		add[i++] = c;
		n--;
	}
	add[i] = '\0';
	if (!(res = ft_strnew(data->size + 1)))
		return (NULL);
	ft_strncpy(res, data->arg, size);
	ft_strncat(res, add, size, ft_strlen(add));
	ft_strdel(&data->arg);
	ft_strdel(&add);
	return (res);
}
