/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:11:34 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/07 23:30:10 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

static t_node 	*ft_new_node()
{
	t_node		*new;

	new = malloc(sizeof(t_node));
	if(!new)
		return (NULL);
    new->index = 0;
    new->cost = 0;
    new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	return (new);
}

void	ft_fill_stack(t_stack *stack, int argc, char *argv[], int c)  // i 0
{
	t_node	*new;
	int		i;

    if (stack == NULL)
        return;
    i = argc;
    while (i >= c)
    {
        new = ft_new_node();
        if (!new)
        {
            ft_free_stack(stack);
            return;
        }
        new->data = ft_atol(argv[i]);
        if (stack->top == NULL)
        {   
            new->next = NULL;
			new->prev = NULL;
            stack->top = new;  
        }    
        else
            ft_nodeadd_front(stack, new);
        stack->size++;
		i--;
    }
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	ft_printf("%s %s %s\n", "val", "index" , "cost");
	while (current != NULL)
	{
		ft_printf("%d	 %d 	%d\n", current->data, current->index, current->cost);
		current = current->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void 	ft_free_both(t_stack *stacka, t_stack *stackb)
{
	if (stacka)
		ft_free_stack(stacka);
	if (stackb)
		ft_free_stack(stackb);
}