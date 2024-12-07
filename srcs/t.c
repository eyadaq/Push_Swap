#include "../includes/push_swap.h"

// Find the node with the smallest index in the stack
t_node *ft_find_min(t_stack *stack)
{
    t_node *min = stack->top;
    t_node *current = stack->top;

    while (current)
    {
        if (current->data < min->data)
            min = current;
        current = current->next;
    }
    return min;
}

// Find the node with the largest index in the stack
t_node *ft_find_max(t_stack *stack)
{
    t_node *max = stack->top;
    t_node *current = stack->top;

    while (current)
    {
        if (current->data > max->data)
            max = current;
        current = current->next;
    }
    return max;
}

// Determine the rotation direction (1 for reverse, 0 for forward)
int ft_get_rotation_direction(int index, int stack_size)
{
    return index > stack_size / 2;
}

// Find the target position in stack B for a node from stack A
t_node *ft_find_target_in_b(t_stack *b, int value)
{
    t_node *target = NULL;
    t_node *current = b->top;

    // Find the largest node in B that is smaller than the value
    while (current)
    {
        if (current->data < value)
        {
            if (!target || current->data > target->data)
                target = current;
        }
        current = current->next;
    }

    // If no smaller node found, return the max node
    return target ? target : ft_find_max(b);
}

// Calculate the cost of moving a node
int ft_calculate_move_cost(t_stack *a, t_stack *b, t_node *node_a, t_node *target_b)
{
    int cost_a, cost_b;

    // Calculate rotation costs for stack A
    if (ft_get_rotation_direction(node_a->index, a->size))
        cost_a = a->size - node_a->index;  // Reverse rotation
    else
        cost_a = node_a->index;  // Forward rotation

    // Calculate rotation costs for stack B
    if (ft_get_rotation_direction(target_b->index, b->size))
        cost_b = b->size - target_b->index;  // Reverse rotation
    else
        cost_b = target_b->index;  // Forward rotation

    // If rotations are in the same direction, take the max
    if (ft_get_rotation_direction(node_a->index, a->size) == 
        ft_get_rotation_direction(target_b->index, b->size))
    {
        return (cost_a > cost_b ? cost_a : cost_b);
    }

    // Otherwise, sum the costs
    return cost_a + cost_b;
}

// Rotate stacks to prepare for pushing
void ft_rotate_for_push(t_stack *a, t_stack *b, t_node *node_a, t_node *target_b)
{
    // Rotate stack A
    while (node_a->index != 0)
    {
        if (ft_get_rotation_direction(node_a->index, a->size))
            ft_rra(a, NULL);
        else
            ft_ra(a, NULL);
    }

    // Rotate stack B
    while (target_b->index != 0)
    {
        if (ft_get_rotation_direction(target_b->index, b->size))
            ft_rrb(b, NULL);
        else
            ft_rb(b, NULL);
    }
}

// Find the node with the least cost to move from A to B
t_node *ft_find_least_cost_node(t_stack *a, t_stack *b)
{
    t_node *least_cost_node = NULL;
    int min_cost = INT_MAX;
    
    // Get current indexes
    ft_get_indexes(a);
    ft_get_indexes(b);

    t_node *current = a->top;
    while (current)
    {
        t_node *target = ft_find_target_in_b(b, current->data);
        int cost = ft_calculate_move_cost(a, b, current, target);

        if (cost < min_cost)
        {
            min_cost = cost;
            least_cost_node = current;
        }
        current = current->next;
    }

    return least_cost_node;
}

// Main Turk algorithm sorting function
void ft_sort_large(t_stack *a, t_stack *b)
{
    // Push first two elements to B
    ft_pb(a, b);
    ft_pb(a, b);

    // Ensure B is somewhat sorted
    if (b->top->data < b->top->next->data)
        ft_sbs(b);

    // Push elements from A to B
    while (a->size > 3)
    {
        t_node *least_cost_node = ft_find_least_cost_node(a, b);
        t_node *target = ft_find_target_in_b(b, least_cost_node->data);
        
        // Rotate stacks to prepare for push
        ft_rotate_for_push(a, b, least_cost_node, target);
        
        // Push to B
        ft_pb(a, b);
    }

    // Sort last 3 elements in A
    ft_sort_three(a);

    // Push back all elements from B to A
    while (b->size > 0)
    {
        // Find the best node to push back
        t_node *push_node = ft_find_max(b);
        
        // Rotate to top
        while (push_node->index != 0)
        {
            if (ft_get_rotation_direction(push_node->index, b->size))
                ft_rrb(b, NULL);
            else
                ft_rb(b, NULL);
        }

        // Push back to A
        ft_pa(b, a);
    }

    // Final alignment of A
    while (!ft_checksorted(a))
    {
        if (ft_get_rotation_direction(ft_find_min(a)->index, a->size))
            ft_rra(a, NULL);
        else
            ft_ra(a, NULL);
    }
}