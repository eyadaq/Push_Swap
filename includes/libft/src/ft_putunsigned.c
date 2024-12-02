/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:21:05 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/09/12 19:48:03 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putunsigned(unsigned int digit)
{
	int	c;

	c = 0;
	if (digit >= 10)
		c += ft_putunsigned(digit / 10);
	c += ft_putchar_fd(((digit % 10) + '0'), 1);
	return (c);
}
