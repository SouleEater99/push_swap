/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:36:45 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/02 11:38:31 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_compare_node(t_list *value1, t_list *value2)
{
	if (value1->nbr > value2->nbr)
		return (1);
	return (0);
}

t_list	*ft_to_lower(t_list *stack)
{
	t_list	*tmp;
	t_list	*lower;

	if (ft_lstsize(stack) == 0)
		return (NULL);
	tmp = stack;
	lower = stack;
	while (tmp->next)
	{
		if (ft_compare_node(lower, tmp->next))
			lower = tmp->next;
		tmp = tmp->next;
	}
	return (lower);
}

t_list	*ft_to_bigger(t_list *stack)
{
	t_list	*tmp;
	t_list	*bigger;

	if (ft_lstsize(stack) == 0)
		return (NULL);
	tmp = stack;
	bigger = stack;
	while (tmp->next)
	{
		if (!ft_compare_node(bigger, tmp->next))
			bigger = tmp->next;
		tmp = tmp->next;
	}
	return (bigger);
}

int	ft_offset(t_list *stack, t_list *node)
{
	int	i;

	i = 1;
	if (ft_lstsize(stack) == 0)
		return (0);
	while (stack != node)
	{
		stack = stack->next;
		i++;
		if (!stack)
			return (0);
	}
	return (i);
}

t_list	*ft_near_node(t_list *a, t_list *b, t_info *info, t_add *add)
{
	t_list	*tmp;
	t_list	*save;
	int		lower;
	int		i;

	tmp = a;
	i = 1;
	add->offset = 1;
	add->near = tmp;
	lower = ft_move_number(b, info, add);
	save = tmp;
	while (tmp)
	{
		add->near = tmp;
		if (lower > ft_move_number(b, info, add))
		{
			save = tmp;
			add->offset = i;
			lower = ft_move_number(b, info, add);
		}
		tmp = tmp->next;
		i++;
		add->offset = i;
	}
	return (save);
}
