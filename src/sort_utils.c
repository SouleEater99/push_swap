/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:39:07 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/03 10:28:04 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (info->top_a >= info->top_b)
	{
		while (info->top_b-- > 0)
		{
			ft_rotation(stack_a, 'r');
			ft_rotation(stack_b, '2');
			info->top_a--;
		}
	}
	else
	{
		while (info->top_a-- > 0)
		{
			ft_rotation(stack_a, 'r');
			ft_rotation(stack_b, '2');
			info->top_b--;
		}
	}
}

void	ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (info->bottom_a >= info->bottom_b)
	{
		while (info->bottom_b-- > 0)
		{
			ft_reverse_rotation(stack_a, 'r');
			ft_reverse_rotation(stack_b, '2');
			info->bottom_a--;
		}
	}
	else
	{
		while (info->bottom_a-- > 0)
		{
			ft_reverse_rotation(stack_a, 'r');
			ft_reverse_rotation(stack_b, '2');
			info->bottom_b--;
		}
	}
}

void	ft_sort_b_remain(t_list **stack_a, t_list **stack_b, t_info *info)
{
	if (info->bottom_a >= info->top_a)
		while (info->top_a-- > 0)
			ft_rotation(stack_a, 'a');
	else
		while (info->bottom_a-- > 0)
			ft_reverse_rotation(stack_a, 'a');
	if (info->bottom_b >= info->top_b)
		while (info->top_b-- > 0)
			ft_rotation(stack_b, 'b');
	else
		while (info->bottom_b-- > 0)
			ft_reverse_rotation(stack_b, 'b');
	ft_push(stack_a, stack_b, info, 'b');
}

int	ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > 0)
		return (0);
	while (stack_a->next)
	{
		if (ft_compare_node(stack_a, stack_a->next))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_free_lst(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
