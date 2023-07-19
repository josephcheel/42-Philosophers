#include "../inc/philo.h"

void	ft_delete_table(t_philo **head)
{
	t_philo	*tmp;

	tmp = *head;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

t_philo	*ft_find_value(t_philo *head, int value)
{
	t_philo	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_philo	*ft_create_new_philo(int value)
{
	t_philo	*result;

	result = malloc(sizeof(t_philo));
	if (!result)
		return (NULL);
	result->value = value;
	result->fork = true;
	result->next = NULL;
	return (result);
}

t_philo	*ft_insert_at_head(t_philo **head, t_philo *philo_to_insert)
{
	philo_to_insert->next = *head;
	*head = philo_to_insert;
	return (philo_to_insert);
}

void	ft_make_circle(int size, t_philo *philo)
{
	t_philo	*tmp;

	tmp = ft_find_value(philo, size);
	tmp->next = ft_find_value(philo, 1);
	tmp->next->first = true;
}

t_philo	*ft_create_table(int size)
{
	int		i;
	t_philo	*table;
	t_philo	*temp;

	i = size;
	table = NULL;
	while (i > 0)
	{
		temp = ft_create_new_philo(i);
		if (!temp)
		{
			ft_delete_table(&table);
			return (NULL);
		}
		ft_insert_at_head(&table, temp);
		i--;
	}
	ft_make_circle(size, table);
	return (table);
}