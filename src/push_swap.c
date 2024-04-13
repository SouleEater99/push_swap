/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:14:49 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/02 11:15:13 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_stack(t_list **a, t_list **b)
{
	t_info	*info;
	t_add	*add;

	info = (t_info *)malloc(sizeof(t_info));
	add = (t_add *)malloc(sizeof(t_add));
	ft_assing_len(*a, *b, info);
	if (info->len_a <= 3)
		ft_sort_3(a);
	else
	{
		while (info->len_a > 3 && info->len_b < 2)
			ft_push(a, b, info, 'b');
		ft_assing_add(*b, add);
		ft_main_sort(a, b, info, add);
	}
	free(info);
	free(add);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;
	char	**tab;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		str = ft_merge_arg(av);
		tab = ft_split(str, ' ');
		if (str)
			free(str);
		if (!tab)
			return (0);
		if (ft_check_paramters(ac, av, tab) == -1)
			return (ft_free_lst(tab), write(2, "Error\n", 6), 0);
		stack_a = ft_fill_stack_a(stack_a, tab);
		if (!ft_check_sort(stack_a, stack_b))
			ft_sort_stack(&stack_a, &stack_b);
		ft_free_lst(tab);
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
	}
}
