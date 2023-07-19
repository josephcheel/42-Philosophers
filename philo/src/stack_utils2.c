/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:36:59 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 23:53:18 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}

int	ft_find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*tmp;

	biggest = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

void	ft_move_to_top(t_stack **head, int index_to_move)
{
	t_stack	*tmp;

	tmp = ft_find_index(*head, index_to_move);
	if (tmp->up)
		while (*head != tmp)
			ft_ra(head, 1);
	else
		while (*head != tmp)
			ft_rra(head, 1);
}

int	ft_find_smallest_cost_int(t_stack *stack)
{
	int		smallest;
	t_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cost < smallest)
		{
			smallest = tmp->cost;
		}
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (smallest == tmp->cost)
		{
			break ;
		}
		tmp = tmp->next;
	}
	return (tmp->index);
}
