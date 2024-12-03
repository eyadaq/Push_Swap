/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:53 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/02 11:43:55 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print(node *stack_a)
{
    node *tmp;

    tmp = stack_a;
    while (tmp)
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void make_it_okay(node **stack_a)
{
    node *tmp;

    tmp = smallest_info(*stack_a);
    if (find_node(stack_a, tmp->info) < size_node(*stack_a) / 2)
    {
        while (tmp->info != (*stack_a)->info)
        {
            rotate(stack_a);
            printf("ra\n");
        }
    }
    else
    {
        while (tmp->info != (*stack_a)->info)
        {
            rrotate(stack_a);
            printf("rra\n");
        }
    }
}
int main(int c, char **v)
{
    node *stack_a;
    node *stack_b;
    cheepest_move *tmp;
    
    tmp = malloc(sizeof(cheepest_move));
    if (!tmp)
        return -1;
    tmp->the_cost = -1;
    stack_a = NULL;
    stack_b = NULL;
    for (int i = 1; i < c; i++)
    {
        if (add_node(&stack_a, atoi(v[i])) == -1)
            return -1;
    }
    // print(stack_a);
    int size = size_node(stack_a);
    if (size > 3)
    {
        push(&stack_a, &stack_b);
        printf("pb\n");
        size--;
        push(&stack_a, &stack_b);
        printf("pb\n");
        size--;
        while (size > 3)
        {
            tmp->the_cost = -1;
            sort_a_b(&stack_a,&stack_b, tmp);
            see_tmp_and_do_the_the_thing(&stack_a, &stack_b, tmp);
            push(&stack_a, &stack_b);
            printf("pb\n");
            size--;
        }
    }
    // print(stack_a);
    sort_three(&stack_a);
    // print(stack_a);
    // print(stack_b);
    while (size_node(stack_b) != 0)
    {
        tmp->the_cost = -1;
        sort_b_a(&stack_a,&stack_b, tmp);
        see_tmp_and_do_the_the_thing(&stack_a, &stack_b, tmp);
        push(&stack_b, &stack_a);
        printf("pa\n");
    }
    make_it_okay(&stack_a);
    // print(stack_a);
    clear_all_nodes(&stack_a);
    clear_all_nodes(&stack_b);
    free(tmp);
}