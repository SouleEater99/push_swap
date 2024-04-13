/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:15:40 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/02 11:31:33 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_stack_b(t_list **a, t_list **b, t_info *info, t_add *add)
{
	add->pos = ft_get_pos_b(*b, info, add);
	ft_assing_a(info, ft_offset(*a, add->near));
	ft_assing_b(info, ft_offset(*b, add->pos));
	if (info->bottom_a >= info->top_a && info->bottom_b >= info->top_b)
		ft_sort_b_equal_top(a, b, info);
	else if (info->bottom_a <= info->top_a && info->bottom_b <= info->top_b)
		ft_sort_b_equal_bottom(a, b, info);
	ft_sort_b_remain(a, b, info);
}

void	ft_sort_3(t_list **stack_a)
{
	t_list	*bigger;
	int		offset;

	bigger = ft_to_bigger(*stack_a);
	offset = ft_offset(*stack_a, bigger);
	if (offset != 3 && ft_lstsize(*stack_a) > 2)
	{
		if (ft_lstsize(*stack_a) - offset >= offset)
			ft_rotation(stack_a, 'a');
		else
			ft_reverse_rotation(stack_a, 'a');
	}
	if (ft_compare_node(*stack_a, (*stack_a)->next))
		ft_swap(stack_a, 'a');
}

void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int		offset;
	t_list	*pos;
	int		top_a;
	int		bottom_a;

	pos = ft_get_pos_a(*stack_b, stack_a);
	offset = ft_offset(*stack_a, pos);
	top_a = offset - 1;
	bottom_a = ft_lstsize(*stack_a) - offset + 1;
	if (bottom_a >= top_a)
	{
		while (top_a-- > 0)
			ft_rotation(stack_a, 'a');
	}
	else
		while (bottom_a-- > 0)
			ft_reverse_rotation(stack_a, 'a');
	ft_push(stack_b, stack_a, info, 'a');
}

void	ft_main_sort(t_list **a, t_list **b, t_info *info, t_add *add)
{
	while (info->len_a > 3)
	{
		add->near = ft_near_node(*a, *b, info, add);
		ft_sort_stack_b(a, b, info, add);
		if (ft_compare_node(add->near, add->bigger))
			add->bigger = add->near;
		else if (!ft_compare_node(add->near, add->lower))
			add->lower = add->near;
	}
	ft_sort_3(a);
	while (info->len_b > 0)
		ft_sort_stack_a(a, b, info);
	ft_assing_a(info, ft_offset(*a, ft_to_lower(*a)));
	if (info->bottom_a >= info->top_a)
		while (info->top_a-- > 0)
			ft_rotation(a, 'a');
	else
		while (info->bottom_a-- > 0)
			ft_reverse_rotation(a, 'a');
}
