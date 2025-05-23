/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:13:51 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/21 03:12:38 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack->top;
	while (current != NULL && current->next != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
			{
				ft_error();
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

static int	ft_check_int_size(const char *c)
{
	long	num;

	num = ft_atol(c);
	if (num < INT_MIN || num > INT_MAX)
	{
		return (1);
	}
	return (0);
}

static int	ft_check_int(int argc, char *argv[], int c)
{
	int	i;
	int	j;

	i = c;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || ft_check_int_size(argv[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	ft_check_fill(t_stack *stack, int argc, char **argv, int c)
{
	if (ft_check_int(argc, argv, c))
	{
		ft_error();
		ft_free_stack(stack);
		return (1);
	}
	if (c == 1)
		ft_fill_stack(stack, (argc - 1), argv, 1);
	if (c == 0)
		ft_fill_stack(stack, (argc - 1), argv, 0);
	if (ft_check_duplicates(stack))
	{
		ft_free_stack(stack);
		return (1);
	}
	return (0);
}
