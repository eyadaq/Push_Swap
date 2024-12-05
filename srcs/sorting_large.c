/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/05 11:40:55 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
1. sort_a_b
Purpose: Determines the optimal move to transfer a node from stack A to stack B based on the calculated cost.
Inputs:
node **stack_a: Pointer to stack A.
node **stack_b: Pointer to stack B.
cheepest_move *tmp: Pointer to a structure storing the cheapest move information.
Operation:
Iterates through each node in stack A.
For each node, finds the best target node in stack B using find_tar_a_b.
Computes the cost of moving the node from stack A to stack B using co_cost.
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
Updates tmp if the cost is lower than the currently stored cost.
Output: Updates the tmp structure with the details of the cheapest move.
*/

t_node *find_target(t_stack *stack, t_node *node)
{
    t_node *target;
    t_node *current;

    if (!stack || !node || !stack->top)
        return NULL;

    target = ft_get_max(stack); 
    current = stack->top;

    while (current)
    {
        if (current->data < node->data)
        {
            if (target->data > node->data || target->data > current->data)
            {
                target = current;
            }
        }
        current = current->next;
    }
    return target;
}

int     ft_cost(t_stack *a, t_stack *b, t_node *na, t_node *nb)
{
    
}
void    ft_calculate_costs(t_stack *a, t_stack *b)
{
    t_node  *sa;
    t_node   *sb;

    sa = a->top;
    sb = b->top;
    
    while (sa)
    {
        sa->target = find_target(b, sa);
        sa->cost = 
        sa = sa->next;
    }
    
}

t_node      *ft_least_cost(t_stack *a, t_stack *b)
{
    t_node  *node;
    t_node  *least;
    
    ft_get_indexes(a);
    ft_get_indexes(b);
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

int     up_or_down(int tmp, t_stack *stack_a)
{
    if (tmp > (stack_a->size / 2))
        return (1);
    else
        return (0);
}


/*
3. up_or_down
Purpose: Determines whether to move a node upward or downward based on its position in the stack.
Inputs:
int tmp: Position of the node in the stack.
node **stack_a: Pointer to stack A.
Operation:
Compares the position of the node to half the size of the stack.
Returns 1 for upward movement and 0 for downward movement.
Output: Integer indicating the direction of movement.
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