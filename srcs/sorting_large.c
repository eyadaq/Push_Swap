/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/05 20:09:30 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void 	ft_get_indexes(t_stack *stack)
{
    t_node *current;
    int i;

    i = 1;
    current = stack->top;
    while (i <= stack->size)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}

t_node     *ft_get_max(t_stack *stack)
{
    t_node  *node;
    int     max;
    t_node  *maxnode;

    node = stack->top;
    max = node->data;
    maxnode = stack->top;
    while (node)
    {
        if (node->data > max)
        {
            max = node->data;
            maxnode = node;           
        }
        node = node->next;
    }
    return (maxnode);   
}
int     up_or_down(int tmp, t_stack *stack_a)
{
    if (tmp > (stack_a->size / 2))
        return (1);
    else
        return (0);
}

t_node *find_target(t_stack *stack, t_node *node)
{
    t_node *target; 
    t_node *current;

    if (!stack || !node || !stack->top)
        return NULL;

    current = stack->top;
    target = NULL;
    while (current)
    {
        if (current->data < node->data)
        {
            if (!target || current->data > target->data)
            {
                target = current;
            }
        }
        current = current->next;
    }
    if (!target)
        target = ft_get_max(stack);
    return target;
}

int     ft_cost(t_stack *a, t_stack *b, t_node *na, t_node *nb)
{
    int     cost;
    int     a_cost;
    int     b_cost;

    if (up_or_down(na->index, a) == up_or_down(nb->index,b))
    {
        if (up_or_down(na->index, a))
        {
            if ((a->size - na->index) > (b->size - nb->index))
                cost = a->size - na->index;
            else
                cost = b->size - nb->index;;
        }
        else
        {
            if (na->index > nb->index)
                cost = na->index;
            else
                cost = nb->index;
        }
        return (cost);
    }
    if (up_or_down(na->index,a))
        cost = a->size - na->index;
    else
        cost = na->index;
    if (up_or_down(nb->index, b))
        cost += b->size - nb->index;
    else
        cost += nb->index;
    return (cost);
}
void    ft_calculate_costs(t_stack *a, t_stack *b)
{
    t_node   *sa;
    t_node   *sb;

    sa = a->top;
    sb = b->top;
    
    while (sa)
    {
        sa->target = find_target(b, sa);
        sa->cost = ft_cost(a,b,sa,sa->target);
        sa = sa->next;
    }
    return ;
}

t_node      *ft_least_cost(t_stack *a, t_stack *b)
{
    t_node  *node;
    t_node  *least;
    
    //ft_get_indexes(a);
    //ft_get_indexes(b);
    ft_calculate_costs(a,b);
    node = a->top;
    least = node;
    while (node)
    {
        if (node->cost < least->cost)
            least = node;
        node = node->next;
    }
    return (least);
}

// Helper function to create a new node
t_node *create_node(int data, int index)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->index = index;
    new_node->cost = 0;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Helper function to initialize a stack
t_stack *init_stack()
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Helper function to add a node to the stack
void add_node(t_stack *stack, int data, int index)
{
    t_node *new_node = create_node(data, index);
    if (stack->top == NULL)
    {
        stack->top = new_node;
    }
    else
    {
        new_node->next = stack->top;
        stack->top->prev = new_node;
        stack->top = new_node;
    }
    stack->size++;
}

// Helper function to print the stack
void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        printf("Data: %d, Index: %d, Cost: %d\n", current->data, current->index, current->cost);
        current = current->next;
    }
}

// Main function to test the provided functions
int main()
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Add nodes to stack_a
    add_node(stack_a, 10, 5);
    add_node(stack_a, 20, 4);
    add_node(stack_a, 30, 3);
    add_node(stack_a, 40, 2);
    add_node(stack_a, 50, 1);

    // Add nodes to stack_b
    add_node(stack_b, 15, 5);
    add_node(stack_b, 25, 4);
    add_node(stack_b, 35, 3);
    add_node(stack_b, 45, 2);
    add_node(stack_b, 55, 1);

    printf("Initial Stack A:\n");
    print_stack(stack_a);
    printf("Initial Stack B:\n");
    print_stack(stack_b);
    ft_calculate_costs(stack_a, stack_b);
    // Test find_target
    t_node *target = find_target(stack_b, stack_a->top);
    if (target)
        printf("Target for node %d in Stack B: %d\n", stack_a->top->data, target->data);
    else
        printf("No target found for node %d in Stack B\n", stack_a->top->data);

    // Test ft_calculate_costs
    
    printf("Stack A after calculating costs:\n");
    print_stack(stack_a);

    // Test ft_least_cost
    t_node *least_cost_node = ft_least_cost(stack_a, stack_b);
    if (least_cost_node)
        printf("Node with least cost in Stack A: %d, Cost: %d and the target is %d\n", least_cost_node->data, least_cost_node->cost, least_cost_node->target->data);
    else
        printf("No node found with least cost in Stack A\n");

    // Free memory

    return 0;
}

/*
4. co_cost
Purpose: Calculates the combined cost of moving a node from stack A to stack B (or vice versa).
Inputs:
node *a: Pointer to the current node in stack A.
node *b: Pointer to the target node in stack B.
node **stack_a: Pointer to stack A.
node **stack_b: Pointer to stack B.
Operation:
Computes the movement cost for nodes in both stacks.
If the movements are in the same direction, it uses the larger of the two costs.
If the movements are in opposite directions, it sums the costs.
Output: Returns the computed cost.
5. save_in_the_rmp
Purpose: Saves the details of the current cheapest move into the tmp structure.
Inputs:
node *a: Pointer to the current node in stack A.
node *b: Pointer to the target node in stack B.
cheepest_move *tmp: Pointer to the structure storing the move details.
int move: Cost of the move.
Operation:
Stores the source node, target node, and cost in the tmp structure.
6. find_tar_a_b
Purpose: Finds the best target node in stack B for a given node in stack A.
Inputs:
node *a: Pointer to the current node in stack A.
node *b: Pointer to stack B.
Operation:
Compares each node in stack B to the node in stack A.
Finds the node in stack B that minimizes the movement cost.
Output: Returns the best target node.
7. bigest_info
Purpose: Finds the node with the largest value in a stack.
Inputs:
node *a: Pointer to the stack.
Operation:
Iterates through the stack to find the node with the maximum info value.
Output: Returns the node with the largest value.
8. see_tmp_and_do_the_the_thing
Purpose: Executes the moves required to align stack A and stack B based on the details in tmp.
Inputs:
node **stack_a: Pointer to stack A.
node **stack_b: Pointer to stack B.
cheepest_move *tmp: Pointer to the structure storing the move details.
Operation:
Adjusts stack A and stack B to align the nodes for optimal transfer using rotate or rrotate.
Performs combined moves if both stacks require rotation in the same direction.
Output: Modifies both stacks.
9. sort_b_a
Purpose: Determines the optimal move to transfer a node from stack B to stack A.
Inputs:
node **stack_a: Pointer to stack A.
node **stack_b: Pointer to stack B.
cheepest_move *tmp: Pointer to a structure storing the cheapest move information.
Operation:
Similar to sort_a_b, but works in reverse (stack B to stack A).
Output: Updates the tmp structure with the details of the cheapest move.
10. find_tar_b_a
Purpose: Finds the best target node in stack A for a given node in stack B.
Inputs:
node *a: Pointer to stack A.
node *b: Pointer to the current node in stack B.
Operation:
Finds the smallest value in stack A that is larger than the current node in stack B.
Output: Returns the best target node.
11. smallest_info
Purpose: Finds the node with the smallest value in a stack.
Inputs:
node *a: Pointer to the stack.
Operation:
Iterates through the stack to find the node with the minimum info value.
Output: Returns the node with the smallest value.
12. make_it_okay
Purpose: Aligns stack A so that the smallest node is at the top.
Inputs:
node **stack_a: Pointer to stack A.
Operation:
Finds the smallest node.
Rotates or reverse-rotates stack A to move the smallest node to the top.
Output: Modifies stack A.
13. main
Purpose: The entry point of the program, implements the sorting logic.
Operation:
Initializes stacks and reads input.
Moves nodes between stacks A and B while sorting.
Uses helper functions to optimize moves and align stacks.
Cleans up allocated memory at the end.

*/

/*

void sort_a_b(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    node *a;
    node *b;

    a = *stack_a;
    while (a)
    {
        b = find_tar_a_b(a, *stack_b);
        if (tmp->the_cost == -1)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        a = a->next;
    }
}

int up_or_down(int tmp, node **stack_a)
{
    if (tmp > size_node(*stack_a) / 2)
        return (1);
    else
        return (0);
}
int co_cost(node *a, node *b, node **stack_a, node **stack_b)
{
    int co;
    int tmp_a;
    int tmp_b;

    tmp_a = find_node(stack_a, a->info);
    tmp_b = find_node(stack_b, b->info);
    if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
    {
        if (up_or_down(tmp_a, stack_a))
        {
            if ((size_node(*stack_a) - tmp_a) > (size_node(*stack_b) - tmp_b))
                co = (size_node(*stack_a) - tmp_a);
            else
                co = (size_node(*stack_b) - tmp_b);
        }
        else
        {
            if (tmp_a > tmp_b)
                co = tmp_a;
            else
                co = tmp_b;
        }
        // if (tmp_a > tmp_b)
        // {    
        //     co = tmp_a;
        //     if (up_or_down(tmp_a, stack_a))
        //         co = size_node(*stack_a) - co;
        // }
        // else
        // {
        //     co = tmp_b;
        //     if (up_or_down(tmp_b, stack_b))
        //         co = size_node(*stack_b) - co;
        // }    
        return (co);
    }
    if (up_or_down(tmp_a, stack_a))
        co = size_node(*stack_a) - tmp_a;
    else
        co = tmp_a;
    if (up_or_down(tmp_b, stack_b))
        co += size_node(*stack_b) - tmp_b;
    else
        co += tmp_b;
    return (co);
}
void save_in_the_rmp(node *a, node *b, cheepest_move *tmp, int move)
{
    tmp->a = a;
    tmp->b = b;
    tmp->the_cost = move;
}
node *find_tar_a_b(node *a, node *b)
{
    node *tar;

    tar = bigest_info(b);
    while (b)
    {
        if ((b->info < a->info))
            if ((tar->info > a->info || tar->info > b->info))
                tar = b;
        b = b->next;
    }
    return (tar);
}
node *bigest_info(node *a)
{
    node *big;
    big = a;
    while (a)
    {
        if (big->info < a->info)
            big = a;
        a = a->next;
    }
    return (big);
}
void see_tmp_and_do_the_the_thing(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    int tmp_a;
    int tmp_b;

    tmp_a = find_node(stack_a, tmp->a->info);
    tmp_b = find_node(stack_b, tmp->b->info);
    if (up_or_down(tmp_a, stack_a) == up_or_down(tmp_b, stack_b))
    {
        if (up_or_down(tmp_a, stack_a))
        {
            tmp->co_a = size_node(*stack_a) - tmp_a;
            tmp->co_b = size_node(*stack_b) - tmp_b;
            while (tmp->co_a != 0 && tmp->co_b != 0)
            {
                rrotate(stack_a);
                rrotate(stack_b);
                tmp->co_a--;
                tmp->co_b--;
                printf("rrr\n");
            }
            while (tmp->co_a != 0)
            {
                rrotate(stack_a);
                tmp->co_a--;
                printf("rra\n");
            }
            while (tmp->co_b != 0)
            {
                rrotate(stack_b);
                tmp->co_b--;
                printf("rrb\n");
            }
        }
        else
        {
            while (tmp->co_a != 0 && tmp->co_b != 0)
            {
                rotate(stack_a);
                rotate(stack_b);
                tmp->co_a--;
                tmp->co_b--;
                printf("rr\n");
            }
            while (tmp->co_a != 0)
            {
                rotate(stack_a);
                tmp->co_a--;
                printf("ra\n");
            }
            while (tmp->co_b != 0)
            {
                rotate(stack_b);
                tmp->co_b--;
                printf("rb\n");
            }
        }
    }
    else
    {
        if (up_or_down(tmp_a, stack_a))
        {
            tmp->co_a = size_node(*stack_a) - tmp_a;
            while (tmp->co_a != 0)
            {
                rrotate(stack_a);
                tmp->co_a--;
                printf("rra\n");
            }
        }
        else
        {
            while (tmp->co_a != 0)
            {
                rotate(stack_a);
                tmp->co_a--;
                printf("ra\n");
            }
        }
        if (up_or_down(tmp_b, stack_b))
        {
            tmp->co_b = size_node(*stack_b) - tmp_b;
            while (tmp->co_b != 0)
            {
                rrotate(stack_b);
                tmp->co_b--;
                printf("rrb\n");
            }
        }
        else
        {
            while (tmp->co_b != 0)
            {
                rotate(stack_b);
                tmp->co_b--;
                printf("rb\n");
            }
        }
    }
}
void sort_b_a(node **stack_a, node **stack_b, cheepest_move *tmp)
{
    node *a;
    node *b;

    b = *stack_b;
    while (b)
    {
        a = find_tar_b_a(*stack_a, b);
        if (tmp->the_cost == -1)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        else if (co_cost(a, b, stack_a, stack_b) < tmp->the_cost)
        {
            save_in_the_rmp(a, b, tmp, co_cost(a, b, stack_a, stack_b));
            tmp->co_a = find_node(stack_a, a->info);
            tmp->co_b = find_node(stack_b, b->info);
        }
        b = b->next;
    }
}
node *find_tar_b_a(node *a, node *b)
{
    node *tar;

    tar = smallest_info(a);
    while (a)
    {
        if ((a->info > b->info))
        if ((tar->info < b->info || tar->info > a->info))
            tar = a;
        a = a->next;
    }
    return (tar);
}
node *smallest_info(node *a)
{
    node *small;
    small = a;
    while (a)
    {
        if (small->info > a->info)
            small = a;
        a = a->next;
    }
    return (small);
}
*/