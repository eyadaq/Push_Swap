/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:24:50 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/08/31 15:07:47 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
