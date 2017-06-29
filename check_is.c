/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:55:50 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 20:55:54 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		is_number(const char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int		is_name(const char *str)
{
	if (*str == 'L')
		my_error("L in name");
	while (*str)
	{
		if (*str == '-' || *str == '#')
			return (0);
		str++;
	}
	return (1);
}

int		is_comment(const char *s)
{
	if (*s == '#')
		return (1);
	return (0);
}

int		is_link(const char *s)
{
	if (ft_strchr(s, '-'))
		return (1);
	else
		return (0);
}

void	init_matrix(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->lst_size)
	{
		j = 0;
		while (j < lem->lst_size)
		{
			lem->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}
