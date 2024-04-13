/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:29:01 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/03 00:29:03 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_get_pos_a(t_list *target, t_list **stack_a)
{
	t_list	*tmp;
	t_list	*lower;
	t_list	*bigger;

	tmp = *stack_a;
	bigger = ft_to_bigger(*stack_a);
	lower = ft_to_lower(*stack_a);
	if (!ft_compare_node(target, lower) || ft_compare_node(target, bigger))
		return (lower);
	while (lower)
	{
		if (!ft_compare_node(target, lower))
			return (lower);
		lower = lower->next;
	}
	lower = ft_to_lower(*stack_a);
	while (tmp && tmp != lower)
	{
		if (!ft_compare_node(target, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*ft_get_pos_b(t_list *b, t_info *info, t_add *add)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = b;
	tmp2 = add->bigger;
	if (info->len_b < 2)
		return (NULL);
	if (!ft_compare_node(add->near, add->lower) || ft_compare_node(add->near,
			tmp2))
		return (tmp2);
	while (tmp2)
	{
		if (ft_compare_node(add->near, tmp2))
			return (tmp2);
		tmp2 = tmp2->next;
	}
	while (tmp && tmp != add->bigger)
	{
		if (ft_compare_node(add->near, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_move_number_top(t_info *info)
{
	if (info->top_a == 0)
		return (info->top_b + 1);
	else if (info->top_b == 0)
		return (info->top_a + 1);
	else if (info->top_a <= info->top_b)
		return (info->top_b + 1);
	else if (info->top_a > info->top_b)
		return (info->top_a + 1);
	return (info->top_a + 1);
}

int	ft_move_number_bottom(t_info *info)
{
	if (info->bottom_a == 0)
		return (info->bottom_b + 1);
	else if (info->bottom_b == 0)
		return (info->bottom_a + 1);
	else if (info->bottom_a <= info->bottom_b)
		return (info->bottom_b + 1);
	else if (info->bottom_a > info->bottom_b)
		return (info->bottom_a + 1);
	return (info->bottom_a + 1);
}

int	ft_move_number(t_list *b, t_info *info, t_add *add)
{
	ft_assing_a(info, add->offset);
	add->pos = ft_get_pos_b(b, info, add);
	add->offset = ft_offset(b, add->pos);
	ft_assing_b(info, add->offset);
	if (info->bottom_a >= info->top_a && info->bottom_b >= info->top_b)
		return (ft_move_number_top(info));
	else if (info->bottom_a <= info->top_a && info->bottom_b <= info->top_b)
		return (ft_move_number_bottom(info));
	else if (info->bottom_a >= info->top_a && info->bottom_b <= info->top_b)
		return (info->top_a + info->bottom_b + 1);
	else if (info->bottom_a <= info->top_a && info->bottom_b >= info->top_b)
		return (info->bottom_a + info->top_b + 1);
	return (0);
}
