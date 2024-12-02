/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:24:12 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/09/02 23:43:36 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				counter;
	const unsigned char	*src;

	src = (const unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (src[counter] == (unsigned char)c)
			return ((void *)(src + counter));
		counter++;
	}
	return (NULL);
}
