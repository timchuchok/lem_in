/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:05:45 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 21:05:50 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static long		ft_long_atoi(const char *s)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + *s - 48;
		s++;
	}
	return (res * sign);
}

void			check_ants(t_lem *lem)
{
	int ant;

	ant = 0;
	while (lem->input[0][ant])
	{
		if (!ft_isdigit(lem->input[0][ant++]) || lem->input[0][0] == '0')
			my_error("first line is incorrect");
	}
	if (ft_strlen(lem->input[0]) > 10)
		my_error("too many ants");
	if (ft_long_atoi(lem->input[0]) > 2147483647)
		my_error("too many ants");
}

void			check_all(t_lem *lem)
{
	int i;

	i = 1;
	while (lem->input[i])
	{
		if (!is_name(lem->input[i]) && \
			!is_comment(lem->input[i]) && !is_link(lem->input[i]))
			my_error("incorrect string");
		i++;
	}
}

void			check_room_after_start_end(t_lem *lem)
{
	int		i;
	char	*start_room;
	char	*end_room;

	i = 1;
	start_room = NULL;
	end_room = NULL;
	while (lem->input[i + 1])
	{
		if (ft_strequ(lem->input[i], "##start"))
			start_room = lem->input[i + 1];
		if (ft_strequ(lem->input[i], "##end"))
			end_room = lem->input[i + 1];
		i++;
	}
	if (!start_room || !end_room)
		my_error("no end/start room");
	if (!is_name(start_room) || !is_name(end_room))
		my_error("no room after end/start");
}

void			check_same(t_lem *lem)
{
	int		i;
	char	**start_room;
	char	**end_room;

	i = 0;
	while (lem->input[i + 1])
	{
		if (ft_strequ(lem->input[i], "##start"))
			start_room = ft_strsplit(lem->input[i + 1], ' ');
		if (ft_strequ(lem->input[i], "##end"))
			end_room = ft_strsplit(lem->input[i + 1], ' ');
		i++;
	}
	if (ft_strequ(start_room[0], end_room[0]))
		my_error("same start/end");
	free(start_room[0]);
	free(end_room[0]);
	free(start_room[1]);
	free(end_room[1]);
	free(start_room[2]);
	free(end_room[2]);
	free(start_room);
	free(end_room);
}
