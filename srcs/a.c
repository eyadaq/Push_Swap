/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:00:58 by eaqrabaw          #+#    #+#             */
/*   Updated: 2024/12/04 11:02:15 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Function prototypes
void sort_stacks(t_stack *a, t_stack *b, t_node **cheapest);
int calculate_cost(t_node *node_a, t_node *node_b, t_stack *a, t_stack *b);
t_node *find_target_a_to_b(t_node *node_a, t_stack *b);
t_node *find_target_b_to_a(t_node *node_b, t_stack *a);
t_node *find_largest(t_node *list);
t_node *find_smallest(t_node *list);
void execute_moves(t_stack *a, t_stack *b, t_node **cheapest);
int is_move_up(int index, t_stack *stack);
int get_node_index(t_stack *stack, int data);

// Function to sort stack A using moves from stack B
void sort_stacks(t_stack *a, t_stack *b, t_node **cheapest) {
    t_node *current = a->top;

    while (current) {
        t_node *target = find_target_a_to_b(current, b);
        int cost = calculate_cost(current, target, a, b);

        if (!(*cheapest) || cost < (*cheapest)->cost) {
            *cheapest = current;
            (*cheapest)->cost = cost;
        }

        current = current->next;
    }
}
// Calculates the cost of moving two nodes into position
int calculate_cost(t_node *node_a, t_node *node_b, t_stack *a, t_stack *b) {
    int index_a = get_node_index(a, node_a->data);
    int index_b = get_node_index(b, node_b->data);

    int move_a = is_move_up(index_a, a) ? a->size - index_a : index_a;
    int move_b = is_move_up(index_b, b) ? b->size - index_b : index_b;

    if (is_move_up(index_a, a) == is_move_up(index_b, b)) {
        return move_a > move_b ? move_a : move_b;
    }
    return move_a + move_b;
}

// Finds the best target node in stack B for the given node in stack A
t_node *find_target_a_to_b(t_node *node_a, t_stack *b) {
    t_node *current = b->top;
    t_node *target = find_largest(b->top);

    while (current) {
        if (current->data < node_a->data && (target->data > node_a->data || target->data > current->data)) {
            target = current;
        }
        current = current->next;
    }
    return target;
}

// Finds the best target node in stack A for the given node in stack B
t_node *find_target_b_to_a(t_node *node_b, t_stack *a) {
    t_node *current = a->top;
    t_node *target = find_smallest(a->top);

    while (current) {
        if (current->data > node_b->data && (target->data < node_b->data || target->data > current->data)) {
            target = current;
        }
        current = current->next;
    }
    return target;
}

// Finds the largest node in a list
t_node *find_largest(t_node *list) {
    t_node *largest = list;

    while (list) {
        if (list->data > largest->data) {
            largest = list;
        }
        list = list->next;
    }
    return largest;
}

// Finds the smallest node in a list
t_node *find_smallest(t_node *list) {
    t_node *smallest = list;

    while (list) {
        if (list->data < smallest->data) {
            smallest = list;
        }
        list = list->next;
    }
    return smallest;
}

// Checks if a move should be upwards based on the index
int is_move_up(int index, t_stack *stack) {
    return index > stack->size / 2;
}

// Finds the index of a node with the given data in a stack
int get_node_index(t_stack *stack, int data) {
    t_node *current = stack->top;
    int index = 0;

    while (current) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
