/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 03:05:20 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/09/12 04:29:39 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_puthexa(unsigned int hexa, char x)
{
	int		c;
	char	*digits;

	c = 0;
	if (x == 'c')
		digits = "0123456789ABCDEF";
	else if (x == 's')
		digits = "0123456789abcdef";
	else
		return (0);
	if (hexa >= 16)
		c += ft_puthexa(hexa / 16, x);
	c += ft_putchar_fd(digits[hexa % 16], 1);
	return (c);
}
