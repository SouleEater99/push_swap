/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paramters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:28:30 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/30 15:28:49 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_is_number(char *str)
{
	long long	count;
	int			sign;

	count = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' || *str == '+') && *(str + 1))
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		count = (count * 10) + (*str - '0');
		if (sign == -1 && count > 2147483648)
			return (-1);
		if (count > 2147483647 && sign == 1)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (1);
}

int	ft_check_parsing(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (i < ac)
		if (av[i++][0] == '\0')
			return (-1);
	i = 0;
	while (av[++i])
	{
		j = 0;
		count = 0;
		while (av[i][j])
			if (av[i][j++] != ' ')
				count++;
		if (count == 0)
			return (-1);
	}
	return (1);
}

int	ft_check_paramters(int ac, char **av, char **tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (ft_check_parsing(ac, av) == -1)
		return (-1);
	while (tab[i])
	{
		if (ft_check_is_number(tab[i]) == -1)
			return (-1);
		tmp = ft_atoi(tab[i]);
		j = i + 1;
		while (tab[j])
			if (tmp == ft_atoi(tab[j++]))
				return (-1);
		i++;
	}
	return (1);
}

t_list	*ft_fill_stack_a(t_list *stack_a, char **tab)
{
	int		i;
	t_list	*current;

	i = 0;
	stack_a = ft_lstnew(ft_atoi(tab[i++]));
	while (tab[i])
	{
		current = ft_lstnew(ft_atoi(tab[i++]));
		ft_lstadd_back(&stack_a, current);
	}
	return (stack_a);
}

char	*ft_merge_arg(char **av)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 1;
	while (av[i])
		tmp = ft_strjoin_2(tmp, av[i++]);
	return (tmp);
}
