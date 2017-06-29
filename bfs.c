/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:32:14 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 14:32:16 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		bfs(t_lem *lem)
{
	int i;
	int cur;

	while (!is_empty(lem))
	{
		cur = front(lem);
		pop(lem);
		i = 0;
		while (i < lem->lst_size)
		{
			if (lem->matrix[cur][i] == 1 && !lem->used[i])
			{
				push(lem, i);
				lem->used[i] = 1;
				lem->dst[i] = lem->dst[cur] + 1;
				lem->prev[i] = cur;
			}
			i++;
		}
	}
}

t_route		*create_route(int *route, t_lem *lem)
{
	int		i;
	t_route *new_route;

	i = 0;
	while (route[i] != -1 && i < lem->lst_size)
		i++;
	new_route = (t_route *)malloc(sizeof(t_route));
	if (!new_route)
		std_error();
	new_route->route = (int *)malloc(sizeof(int) * i);
	new_route->is_ant_here = (int *)malloc(sizeof(int) * i);
	new_route->route_len = i;
	if (!new_route->route || !new_route->is_ant_here)
		std_error();
	ft_bzero(new_route->is_ant_here, sizeof(int) * i);
	i = 0;
	while (i < new_route->route_len)
	{
		new_route->route[i] = route[i];
		i++;
	}
	return (new_route);
}

void		reset_for_bfs(t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->lst_size)
	{
		lem->dst[i] = -1;
		lem->route[i] = -1;
		i++;
	}
	i = 0;
	while (i < lem->lst_size * lem->lst_size)
	{
		lem->queue[i] = -1;
		i++;
	}
	ft_bzero(lem->used, sizeof(int) * lem->lst_size);
	ft_bzero(lem->prev, sizeof(int) * lem->lst_size);
}

void		create_all(t_lem *lem)
{
	lem->used = (int *)malloc(lem->lst_size * sizeof(int));
	lem->dst = (int *)malloc(lem->lst_size * sizeof(int));
	lem->prev = (int *)malloc(lem->lst_size * sizeof(int));
	lem->queue = (int *)malloc(lem->lst_size * lem->lst_size * sizeof(int));
	lem->route = (int *)malloc(lem->lst_size * sizeof(int));
	lem->routes = (t_route **)malloc(lem->lst_size * sizeof(t_route *));
	if (!lem->used || !lem->dst || !lem->prev || \
		!lem->queue || !lem->route || !lem->routes)
		std_error();
}
