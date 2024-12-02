/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 04:38:42 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/09/12 04:47:36 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_putptr_helper(size_t hexa, char x)
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
		c += ft_putptr_helper(hexa / 16, x);
	c += ft_putchar_fd(digits[hexa % 16], 1);
	return (c);
}

int	ft_putptr(void *ptr)
{
	int		c;
	size_t	value;

	c = 0;
	value = (size_t)ptr;
	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	c = ft_putstr_fd("0x", 1);
	return (ft_putptr_helper(value, 's') + c);
}
