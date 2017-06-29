/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:17:27 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 14:20:47 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_name(t_lem *lem, int index)
{
	t_room *lst;

	lst = lem->room_lst;
	while (lst)
	{
		if (lst->index == index)
			ft_printf("%s", lst->name);
		lst = lst->next;
	}
}

void	push_front(t_lem *lem, int index)
{
	int i;

	i = lem->lst_size - 1;
	while (i != 0)
	{
		lem->route[i] = lem->route[i - 1];
		i--;
	}
	lem->route[0] = index;
}

void	route(t_lem *lem, int cur)
{
	int i;

	i = 0;
	push_front(lem, cur);
	while (lem->prev[cur] != -1)
	{
		cur = lem->prev[cur];
		push_front(lem, cur);
	}
	while (lem->routes[i])
		i++;
	lem->routes[i] = create_route(lem->route, lem);
}

int		get_start(t_lem *lem)
{
	t_room *room;

	room = lem->room_lst;
	while (room)
	{
		if (room->start)
			return (room->index);
		room = room->next;
	}
	return (-1);
}

int		get_end(t_lem *lem)
{
	t_room *room;

	room = lem->room_lst;
	while (room)
	{
		if (room->end)
			return (room->index);
		room = room->next;
	}
	return (-1);
}
