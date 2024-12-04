/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:06:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/04 07:34:40 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void ft_free_args(char **args)
{
    int 	i;
	
	i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

static void handle_two_arguments(t_stack *stack_a, t_stack *stack_b, char *arg)
{
    char **args;
    int 	i;
	
	i = 0;
    args = ft_split(arg, ' ');
    while (args[i])
        i++;
    if (ft_check_fill(stack_a, i, args, 0))
    {
        i = 0;
        ft_free_args(args);
        ft_free_stack(stack_b);
        exit(-1);
    }
    ft_free_args(args);
    ft_sort_small(stack_a, stack_b);
    ft_free_both(stack_a, stack_b);
}

static void handle_multiple_arguments(t_stack *stack_a, t_stack *stack_b, int argc, char *argv[])
{
    if (ft_check_fill(stack_a, argc, argv, 1))
    {
        ft_free_stack(stack_b);
        exit(-1);
    }
    ft_printf("%s\n", "Operations used in sorting:");
    ft_sort_large(stack_a, stack_b);
    ft_printf("%s\n", "After Sorting :");
    ft_print_stack(stack_a);
    ft_printf("-------------stack A-------------------------------\n");
    ft_printf("stack a size = %d\n", stack_a->size);
    ft_print_stack(stack_b);
    ft_printf("-------------stack B-------------------------------\n");
    ft_free_both(stack_a, stack_b);
}

static void initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
    *stack_a = ft_init_stack();
    *stack_b = ft_init_stack();
    if (!*stack_a || !*stack_b)
    {
        ft_free_both(*stack_a, *stack_b);
        ft_error();
        exit(-1);
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);

    initialize_stacks(&stack_a, &stack_b);

    if (argc == 2)
    {
        handle_two_arguments(stack_a, stack_b, argv[1]);
    }
    else
    {
        handle_multiple_arguments(stack_a, stack_b, argc, argv);
    }
    return (0);
}