/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:46:46 by ael-maim          #+#    #+#             */
/*   Updated: 2024/02/02 11:43:23 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_list
{
	int				nbr;
	struct t_list	*next;
}					t_list;

typedef struct t_info
{
	int				top_a;
	int				bottom_a;
	int				top_b;
	int				bottom_b;
	int				len_a;
	int				len_b;
}					t_info;

typedef struct t_add
{
	t_list			*near;
	t_list			*pos;
	t_list			*target;
	t_list			*lower;
	t_list			*bigger;
	int				offset;

}					t_add;

void				ft_sort_b_equal_top(t_list **stack_a, t_list **stack_b,
						t_info *info);
void				ft_sort_b_equal_bottom(t_list **stack_a, t_list **stack_b,
						t_info *info);
void				ft_sort_b_remain(t_list **stack_a, t_list **stack_b,
						t_info *info);
int					ft_check_sort(t_list *stack_a, t_list *stack_b);
char				*ft_strjoin_2(char *str1, char *str2);
void				ft_sort_stack_b(t_list **stack_a, t_list **stack_b,
						t_info *info, t_add *add);
void				ft_sort_3(t_list **stack_a);
void				ft_sort_stack_a(t_list **stack_a, t_list **stack_b,
						t_info *info);
void				ft_assing_a(t_info *info, int offset);
void				ft_assing_b(t_info *info, int offset);
void				ft_assing_len(t_list *a, t_list *b, t_info *info);
void				ft_assing_add(t_list *b, t_add *add);
void				ft_sort_stack(t_list **a, t_list **b);
t_list				*ft_get_pos_a(t_list *target, t_list **stack_a);
t_list				*ft_get_pos_b(t_list *b, t_info *info, t_add *t_add);
int					ft_move_number_top(t_info *info);
int					ft_move_number_bottom(t_info *info);
int					ft_move_number(t_list *b, t_info *info, t_add *add);
void				ft_swap(t_list **stack, char c);
void				ft_push(t_list **stack_1, t_list **stack_2, t_info *info,
						char c);
void				ft_push_checker(t_list **stack_1, t_list **stack_2, char c);
void				ft_rotation(t_list **stack, char c);
void				ft_reverse_rotation(t_list **stack, char c);
int					ft_compare_node(t_list *value1, t_list *value2);
t_list				*ft_to_lower(t_list *stack);
t_list				*ft_to_bigger(t_list *stack);
int					ft_offset(t_list *stack, t_list *node);
t_list				*ft_near_node(t_list *a, t_list *b, t_info *info,
						t_add *add);
int					ft_check_is_number(char *str);
int					ft_check_paramters(int ac, char **av, char **tab);
int					ft_check_parsing(int ac, char **av);
t_list				*ft_fill_stack_a(t_list *stack_a, char **tab);
void				ft_free_lst(char **tab);
char				*ft_merge_arg(char **av);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int nbr);
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
char				*ft_strjoin_2(char *str1, char *str2);
void				ft_main_sort(t_list **a, t_list **b, t_info *info,
						t_add *add);

#endif
