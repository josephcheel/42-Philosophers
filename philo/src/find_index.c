/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:51 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/17 18:21:19 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	index(t_stack *head, int num)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->value <= num)
			i++;
		head = head->next;
	}
	return (i);
}

void	ft_indexation(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		temp->index = index(head, temp->value);
		temp = temp->next;
	}
}
