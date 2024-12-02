/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 08:32:25 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/02 09:11:05 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     ft_calc_bcost(t_stack *b, t_node *node)
{
    int		b_index;
    int		index;
    t_node 		*min;
    t_node 		*max;
    
    min = ft_get_min(b);
    max = ft_get_max(b);
    b_index = 0;
    index = ft_largest_smaller_index(b, node);
    if (node->data < min->data || node->data > max->data)
        b_index = 0;
    else if (index <= (b->size / 2))
        b_index = index;
    else if (index > (b->size / 2))
        b_index = (b->size - index + 2);
    return (b_index);
}

void    make_it_top(t_stack *b)
{
    t_node	*max;

    ft_get_indexes(b);
    max = ft_get_max(b);
    if (max->index == 1)
	    return ;
    if (max->index <= (b->size/2))
    {
        while (max != b->top)
		    ft_rb(b);
    }
    else if (max->index > (b->size / 2))
    {
        while (max != b->top)
		    ft_rrb(b);
    }
    return ;
}
