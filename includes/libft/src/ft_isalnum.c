/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:50:26 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:01 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_isalnum(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else if (x >= 'A' && x <= 'Z')
		return (1);
	else if (x >= 'a' && x <= 'z')
		return (1);
	else
		return (0);
}
