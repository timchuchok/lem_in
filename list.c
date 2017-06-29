/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:41:37 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 14:41:40 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room		*create_room(char *name, int index, int start, int end)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	if (!room)
	{
		perror("Oops");
		exit(1);
	}
	room->name = ft_strdup(name);
	room->index = index;
	room->next = NULL;
	room->start = start;
	room->end = end;
	return (room);
}

void		print_rooms(t_room *head)
{
	if (!head)
		my_error("empty list");
	while (head)
	{
		ft_printf("%i : %s\n", head->index, head->name);
		head = head->next;
	}
}

void		roomaddend(t_room **room_lst, t_room *room)
{
	t_room *l;

	if (*room_lst == NULL)
	{
		*room_lst = room;
		return ;
	}
	l = *room_lst;
	while (l->next)
		l = l->next;
	l->next = room;
}

void		print_room(t_room *room)
{
	ft_printf("Name: %s\n", room->name);
	ft_printf("Index: %d\n", room->index);
	ft_printf("Start: %d\n", room->start);
	ft_printf("End: %d\n", room->end);
}
