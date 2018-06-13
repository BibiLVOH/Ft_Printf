/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:52:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/05/20 00:09:03 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int	real;
	int mine;

	real = 0;
	mine = 0;
	printf("----------REAL------------\n");
	real = printf("toto %##.0xet %#.X%###.1x", 0, 0, 0);
	printf("real = %d\n", real);
	printf("----------MINE------------\n");
	mine = ft_printf("toto %##.0xet %#.X%###.1x", 0, 0, 0);
	printf("mine = %d\n", mine);
	printf("--------------------------\n");
	return (0);
}

//curqui_test
//printf-unit-test
