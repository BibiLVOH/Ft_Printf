/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:43:02 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/17 16:58:01 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

# define CONV_LST "sSpdDioOuUxXcC"
# define ATT_LST "#0-+ "
# define MOD_LST "lhjz"
# define ALL_CHAR "#0-+ lhjz123456789."

# define F_HASH 	1
# define F_SPACE 	2
# define F_ZERO		4
# define F_MINUS	8
# define F_PLUS		16

# define F_L 		32
# define F_LL 		64
# define F_H		128
# define F_HH		256
# define F_J		512
# define F_Z		1024

typedef struct		s_arg
{
	int				flag;
	int				preci;
	int				larg;
	int				size;
	int				len;
	char			*arg;
	char			*buf;
}					t_arg;

typedef struct		s_conv
{
	char			conv;
	int				(*f)(t_arg*, va_list ap);
}					t_conv;

int					ft_printf(const char *format, ...);
void				get_len(char *format, va_list ap, t_arg *data);

int					parse_index(char *fmt, va_list ap, t_arg *data);
int					get_att(char *fmt, t_arg *data);
int					get_mod(char *fmt, t_arg *data);
int					get_pre(char *fmt, t_arg *data);
int					get_width(char *fmt, t_arg *data);

int					convert(char *fmt, va_list ap, t_arg *data);
void				print_rez(t_arg *data);

int					conv_none(char let, t_arg *data);
void				none_minus(t_arg *data);
void				none_space_zero(t_arg *data);

int					conv_c(t_arg *data, va_list ap);
int					conv_s(t_arg *data, va_list ap);
int					conv_i(t_arg *data, va_list ap);
int					conv_u(t_arg *data, va_list ap);
int					conv_p(t_arg *data, va_list ap);
int					conv_maj_d(t_arg *data, va_list ap);
int					conv_maj_u(t_arg *data, va_list ap);
int					conv_o(t_arg *data, va_list ap);
int					conv_maj_o(t_arg *data, va_list ap);
int					conv_x(t_arg *data, va_list ap);
int					conv_maj_x(t_arg *data, va_list ap);

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnstr(char *str, int n);
void				ft_put_nb_max(intmax_t nb);
void				ft_put_u_nb_max(uintmax_t nb);

int					ft_isdigit(int i);
intmax_t			ft_abs(intmax_t n);

char				*ft_strnew(size_t size);
char				*ft_strncat(char *dest, char *src, int l_dest, int l_src);
char				*ft_strncpy(char *dest, char *src, int n);
char				*ft_strdup(char *src);
char				*ft_strndup(const char *src, int nb);

size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_tolower(char *s);
void				ft_strdel(char **as);

char				*ft_strjoin(char *s1, char *s2, t_arg *data);
char				*ft_charjoin(char c, t_arg *data);
char				*ft_x_join(int n, char c, int size, t_arg *data);
char				*ft_join_x(int n, char c, int size, t_arg *data);

int					ft_atoi(const char *str);
char				*ft_itoa_base(intmax_t n, int base);
int					ft_ilen_base(intmax_t	n, int base);
char				*ft_utoa_base(uintmax_t n, int base);
int					ft_ulen_base(uintmax_t	n, int base);

#endif
