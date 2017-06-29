/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:08:24 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 17:08:27 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	push(t_lem *lem, int index)
{
	int i;

	i = 0;
	while (i < lem->lst_size)
	{
		if (lem->queue[i] == -1)
		{
			lem->queue[i] = index;
			return ;
		}
		i++;
	}
}

void	pop(t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->lst_size - 1)
	{
		lem->queue[i] = lem->queue[i + 1];
		i++;
	}
	lem->queue[lem->lst_size - 1] = -1;
}

int		front(t_lem *lem)
{
	return (lem->queue[0]);
}

int		is_empty(t_lem *lem)
{
	if (lem->queue[0] == -1)
		return (1);
	else
		return (0);
}

int		all_in_end(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	if (lem->ants)
		return (0);
	while (lem->routes[i] && i < lem->lst_size)
	{
		j = 1;
		while (j < lem->routes[i]->route_len)
		{
			if (lem->routes[i]->is_ant_here[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
