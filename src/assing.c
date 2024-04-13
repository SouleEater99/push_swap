/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:25:08 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/03 00:27:51 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_assing_a(t_info *info, int offset)
{
	info->top_a = offset - 1;
	info->bottom_a = info->len_a - offset + 1;
}

void	ft_assing_b(t_info *info, int offset)
{
	info->top_b = offset - 1;
	info->bottom_b = info->len_b - offset + 1;
}

void	ft_assing_len(t_list *a, t_list *b, t_info *info)
{
	info->len_a = ft_lstsize(a);
	info->len_b = ft_lstsize(b);
}

void	ft_assing_add(t_list *b, t_add *add)
{
	if (ft_lstsize(b) >= 2)
	{
		if (ft_compare_node(b, b->next))
		{
			add->bigger = b;
			add->lower = b->next;
		}
		else
		{
			add->bigger = b->next;
			add->lower = b;
		}
	}
}

char	*ft_strjoin_2(char *str1, char *str2)
{
	int		i;
	int		len_1;
	char	*new;

	if (!str2)
		return (NULL);
	if (!str1)
		len_1 = 0;
	else
		len_1 = ft_strlen(str1) + 1;
	i = -1;
	new = malloc(len_1 + ft_strlen(str2) + 1);
	if (!new)
		return (NULL);
	while (str1 && str1[++i])
		new[i] = str1[i];
	if (str1)
		new[i] = ' ';
	i = -1;
	while (str2[++i])
		new[len_1 + i] = str2[i];
	new[len_1 + i] = '\0';
	if (str1)
		free(str1);
	return (new);
}
