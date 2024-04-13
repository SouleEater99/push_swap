/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:24:29 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/03 11:05:18 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_checker_input_child(t_list **stack_a, t_list **stack_b, char *line)
{
	int	size;

	size = ft_strlen(line);
	if (ft_strncmp(line, "ra\n", size) == 0)
		return (ft_rotation(stack_a, 'd'), 1);
	else if (ft_strncmp(line, "rb\n", size) == 0)
		return (ft_rotation(stack_b, 'd'), 1);
	else if (ft_strncmp(line, "rr\n", size) == 0)
	{
		ft_rotation(stack_a, 'd');
		ft_rotation(stack_b, 'd');
		return (1);
	}
	else if (ft_strncmp(line, "rra\n", size) == 0)
		return (ft_reverse_rotation(stack_a, 'd'), 1);
	else if (ft_strncmp(line, "rrb\n", size) == 0)
		return (ft_reverse_rotation(stack_b, 'd'), 1);
	else if (ft_strncmp(line, "rrr\n", size) == 0)
	{
		ft_reverse_rotation(stack_a, 'd');
		ft_reverse_rotation(stack_b, 'd');
		return (1);
	}
	return (0);
}

int	ft_checker_input(t_list **stack_a, t_list **stack_b, char *line)
{
	int	size;

	size = ft_strlen(line);
	if (ft_strncmp(line, "sa\n", size) == 0)
		ft_swap(stack_a, 'd');
	else if (ft_strncmp(line, "sb\n", size) == 0)
		ft_swap(stack_b, 'd');
	else if (ft_strncmp(line, "ss\n", size) == 0)
	{
		ft_swap(stack_a, 'd');
		ft_swap(stack_b, 'd');
	}
	else if (ft_strncmp(line, "pa\n", size) == 0)
		ft_push_checker(stack_b, stack_a, 'd');
	else if (ft_strncmp(line, "pb\n", size) == 0)
		ft_push_checker(stack_a, stack_b, 'd');
	else if (ft_checker_input_child(stack_a, stack_b, line) == 0)
		return (write(2, "Error\n", 6), free(line), 0);
	return (free(line), 1);
}

int	ft_read_input(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_checker_input(stack_a, stack_b, line) == 0)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

int	ft_check_sort_2(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > 0)
		return (write(1, "KO\n", 3), 0);
	while (stack_a->next)
	{
		if (ft_compare_node(stack_a, stack_a->next))
			return (write(1, "KO\n", 3), 0);
		stack_a = stack_a->next;
	}
	return (write(1, "OK\n", 3), 1);
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
		ft_free_lst(tab);
		if (ft_read_input(&stack_a, &stack_b) == 0)
			return (ft_lstclear(&stack_a, free), ft_lstclear(&stack_b, free),
				0);
		ft_check_sort_2(stack_a, stack_b);
		return (ft_lstclear(&stack_a, free), ft_lstclear(&stack_b, free), 0);
	}
}
