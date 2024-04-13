/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:50:53 by ael-maim          #+#    #+#             */
/*   Updated: 2024/01/21 10:27:37 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_nl(char *buffer)
{
	if (!buffer)
		return (0);
	while (*buffer)
		if (*buffer++ == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin_line(char *buckup, char *buffer)
{
	char	*new_buckup;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!buckup)
	{
		buckup = malloc(1);
		if (!buckup)
			return (ft_free_line(buffer));
		buckup[0] = '\0';
	}
	new_buckup = malloc(ft_strlen_line(buckup) + ft_strlen_line(buffer) + 1);
	if (!new_buckup)
		return (free(buffer), ft_free_line(buckup));
	while (buckup[++i])
		new_buckup[i] = buckup[i];
	while (buffer[j])
		new_buckup[i++] = buffer[j++];
	new_buckup[i] = '\0';
	return (free(buckup), new_buckup);
}

char	*ft_get_nl(char *buckup)
{
	int		i;
	char	*line;

	i = 0;
	while (buckup[i] && buckup[i] != '\n')
		i++;
	if (buckup[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (ft_free_line(buckup));
	i = 0;
	while (buckup[i] && buckup[i] != '\n')
	{
		line[i] = buckup[i];
		i++;
	}
	if (buckup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_remaind(char *buckup)
{
	char	*remaind;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buckup)
		return (NULL);
	while (buckup[i] && buckup[i] != '\n')
		i++;
	if (buckup[i++] == '\0')
	{
		free(buckup);
		return (NULL);
	}
	remaind = malloc(ft_strlen_line(buckup) - i + 1);
	if (!remaind)
		return (ft_free_line(buckup));
	while (buckup[i])
		remaind[j++] = buckup[i++];
	remaind[j] = '\0';
	free(buckup);
	return (remaind);
}
