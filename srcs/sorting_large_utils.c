// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sorting_large_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/01 08:32:25 by eaqrabaw          #+#    #+#             */
// /*   Updated: 2024/12/04 10:06:08 by eaqrabaw         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/push_swap.h"

// // int ft_calc_bcost(t_stack *b, t_node *node)
// // {
// //     int position;
// //     int cost;
// //     t_node *current;
    
// //     position = 0;
// //     current = b->top;
// //     while (current != NULL)
// //     {
// //         if (current->data == node->data)
// //         {
// //             break;
// //         }
// //         position++;
// //         current = current->next;
// //     }
// //     if (position < b->size / 2)
// //         cost = position;
// //     else
// //         cost = b->size - position;
// //     return cost;
// // }

// t_node *ft_find_largest_smaller_node(t_stack *stack, t_node *node)
// {
//     t_node *current = stack->top;
//     t_node *largest_smaller_node = NULL;

//     while (current != NULL)
//     {
//         // Check if the current node's data is smaller than the given node's data
//         // and is larger than the previously found "largest smaller node"
//         if (current->data < node->data)
//         {
//             if (largest_smaller_node == NULL || current->data > largest_smaller_node->data)
//             {
//                 largest_smaller_node = current;
//             }
//         }
//         current = current->next;
//     }

//     return largest_smaller_node;
// }

// int ft_calc_acost(t_stack *a, t_node *node)
// {
//     int position;
//     int cost;

//     position = 0;
//     t_node *current = a->top;

//     while (current != NULL)
//     {
//         if (current->data == node->data)
//         {
//             break;
//         }
//         position++;
//         current = current->next;
//     }
//     if (position < a->size / 2)
//         cost = position;
//     else
//         cost = a->size - position;
//     return cost;
// }

// void ft_calculate_cost(t_stack *a, t_stack *b)
// {
//     t_node *node = a->top;
//     t_node *largest_smaller;
//     int acost, bcost, total_cost;
    
//     while (node != NULL)
//     {
//         acost = ft_calc_acost(a, node);  // Calculate cost for stack a
//         largest_smaller = ft_find_largest_smaller_node(b, node);
//         if (!largest_smaller)
//         {
//             bcost = 0;
//         }
//         else {
//             bcost = largest_smaller->index;
//         }
//         //ft_calc_bcost(b, largest_smaller);  // Calculate cost for stack b

//         // Calculate the total cost (you can choose to sum or use another logic here)
//         total_cost = acost + bcost;
//         // Save the cost in the node
//         node->cost = total_cost;

//         node = node->next;  // Move to the next node
//     }
// }

// t_node      *ft_get_least_cost(t_stack *a)
// {
//     t_node *node;
//     t_node         *least;

//     node = a->top;
//     least = a->top;

//     while (node)
//     {
//         if (node->cost < least->cost)
//             least = node;
//         node = node->next;
//     }
//     return (least);
// }

// void ft_make_top_a(t_stack *stack, t_node *node)
// {
//     int position = 0;
//     t_node *current = stack->top;

//     // Find the position of the node in the stack
//     while (current != NULL && current != node)
//     {
//         current = current->next;
//         position++;
//     }

//     // If the node is not found, return
//     if (current == NULL)
//         return;

//     // Determine whether to rotate or reverse rotate
//     if (position <= stack->size / 2)
//     {
//         // Rotate until the node is at the top
//         while (stack->top != node)
//         {
//             ft_ra(stack);
//         }
//     }
//     else
//     {
//         // Reverse rotate until the node is at the top
//         while (stack->top != node)
//         {
//             ft_rra(stack);
//         }
//     }
// }


// void ft_make_top_b(t_stack *stack, t_node *node)
// {
//     int position = 0;
//     t_node *current = stack->top;

//     // Find the position of the node in the stack
//     while (current != NULL && current != node)
//     {
//         current = current->next;
//         position++;
//     }

//     // If the node is not found, return
//     if (current == NULL)
//         return;

//     // Determine whether to rotate or reverse rotate
//     if (position <= stack->size / 2)
//     {
//         // Rotate until the node is at the top
//         while (stack->top != node)
//         {
//             ft_rb(stack);
//         }
//     }
//     else
//     {
//         // Reverse rotate until the node is at the top
//         while (stack->top != node)
//         {
//             ft_rrb(stack);
//         }
//     }
// }


// void    ft_make_large_top(t_stack *b)
// {
//     t_node *max;

//     max = ft_get_max(b);
    
//     if (b->top == max)
//         return ;
//     ft_make_top_b(b,max);
//     return ;
// }

// void ft_move_b_to_a(t_stack *a, t_stack *b)
// {
//     t_node *a_top;
//     t_node *b_top;
//     t_node *last;
//     int     i;

//     i = 0;
//     a_top = a->top;
//     b_top = b->top;
//     last = ft_lastnode(a_top);
//     while (b_top)
//     {
//         b_top = b->top;
//         while (b_top->data < last->data && i < 3)
//         {
//             ft_rra(a);
//             i++;
//             last = ft_lastnode(a_top);
//         }
//         ft_pb(a,b);
//     }
// }

// void    ft_sort_large(t_stack *a, t_stack *b)
// {
//     t_node *leastcost;
//     t_node  *target;
//     t_node  *max;
//     t_node  *min;

//     ft_pb(a, b);
//     ft_pb(a, b);
//     if (b->top->data < b->top->next->data)
//         ft_sb(b);
//     while (a->size != 3)
//     {
//         ft_get_indexes(a);
//         ft_get_indexes(b);
//         ft_calculate_cost(a,b);
//         max = ft_get_max(b);
//         min = ft_get_min(b);
//         leastcost = ft_get_least_cost(a);
//         if (leastcost->data > max->data)
//         {
//             target = b->top;
//             ft_make_top_a(a, leastcost);
//             ft_make_top_b(b,target);
//             ft_pb(a,b);
//         }
//         else if (leastcost->data < min->data)
//         {
//             target = b->top;
//             ft_make_top_a(a, leastcost);
//             ft_make_top_b(b,target);
//             ft_pb(a,b);
//             ft_rb(b);
//         }
//         else if (leastcost->data > min->data && leastcost->data < max->data) 
//          {
//             target = ft_find_largest_smaller_node(b, leastcost);
//             ft_make_top_a(a, leastcost);
//             ft_make_top_b(b,target);
//             ft_pb(a,b);
//         }
//           max = ft_get_max(b);
//          ft_make_top_b(b, max);
//     }
//     max = ft_get_max(b);
//     ft_make_top_b(b, max);
//     ft_sort_small(a,b);
//     ft_move_b_to_a(a, b);
//     return ;
// }
// /*
//     1 - Push the first two nodes and sort them in descending order.  --> Done
//     2 - Claculate the costs by:
//         a - Calculate How much moves you need to make the top of the stack A. --> 💀
//         b - Get the index of the larges element that is smaller than the node in A 💀
//         c - Calaculate How much it needs to be the top of the stack. 💀
//         d - Add the steps A and C together and save the index of the target; 💀
//         e - Do it for all of the nodes;💀
//     3 - Select the node with the least push cost;💀
//     4 - Move it to the top and move the b node to the top;💀
//     5 - Push the node and re arrange b.💀
//     6 - Do the same until 3 elements in stack A are left.💀
//     7 - Sort the last 3 elements in A in ascending order,💀
//     8 - ....... To be continued.💀
// */