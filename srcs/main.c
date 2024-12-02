/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:06:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/01 22:21:26 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	char		**args;
	static char		*s;
	
	if (argc < 2)
		return (0);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!stack_a || !stack_b)
    {
		ft_free_both(stack_a,stack_b);
        ft_error();
        return (-1);
    }
	if (2 == argc)
	{
		int	i = 0;
		s = argv[1];
		args = ft_split(s, ' ');
		while (args[i])
			i++;
		if (ft_check_fill(stack_a, i, args, 0))
    	{
			i = 0;
			while (args[i])
			{
				free(args[i]);
				i++;
			}
			free(args);
        	ft_free_stack(stack_b);
        	return (-1);
    	}
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
		ft_sortsmall(stack_a, stack_b);
		ft_free_both(stack_a,stack_b);
		return (0);
	}
	else
	{
		if (ft_check_fill(stack_a, argc, argv, 1))
    	{
        	ft_free_stack(stack_b);
        	return (-1);
    	}
		ft_printf("%s\n", "Before Sorting :");
		ft_get_indexes(stack_a);
		ft_print_stack(stack_a);
		ft_printf("%s\n", "Operations used in sorting:");
		ft_sort_large(stack_a, stack_b);
		ft_printf("%s\n", "After Sorting :");
		ft_print_stack(stack_a);
		ft_printf("-------------stack b-------------------------------\n");
		ft_printf("stack a size = %d\n", stack_a->size);
		ft_print_stack(stack_b);
		ft_free_both(stack_a,stack_b);
		return (0);
	}
	return (0);
}
