/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/07/09 20:09:22 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_node	*ft_create_stack(int size)
{
	int		i;
	t_node	*node;
	t_node	*temp;

	i = size;
	node = NULL;
	while (1 < i)
	{
		temp = ft_create_new_node(i);
		ft_insert_at_head(&node, temp);
		i++;
	}
	if (i == 1)
	{
		temp = ft_create_last_node(i);
		ft_insert_at_head(&node, temp);
	}

	return (node);
}
