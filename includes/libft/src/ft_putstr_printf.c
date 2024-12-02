/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 04:47:51 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/09/12 04:50:48 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putstr_printf(char *ptr)
{
	if (ptr != NULL)
		return (ft_putstr_fd(ptr, 1));
	else
		return (ft_putstr_fd("(null)", 1));
}
