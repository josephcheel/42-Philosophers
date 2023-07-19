/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:51:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 23:53:04 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_find_index(t_stack *head, int index)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*ft_find_smallest_cost(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = head;
	smallest = head;
	while (tmp != NULL)
	{
		if (tmp->cost < smallest->cost)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

t_stack	*ft_find_pos(t_stack *head, int pos)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->pos == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_pos_of_index(t_stack *head, int value)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->index == value)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_listsize(t_stack *head)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
