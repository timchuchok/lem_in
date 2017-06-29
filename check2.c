/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:06:19 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 21:06:20 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	check_links(t_lem *lem)
{
	int		i;
	char	**room;

	i = 1;
	while (lem->input[i])
	{
		if (is_link(lem->input[i]) && \
			!is_comment(lem->input[i]) && !is_name(lem->input[i]))
		{
			room = ft_strsplit(lem->input[i], '-');
			if (!room[0])
				my_error("no room");
			if (!room[1])
				my_error("no room");
			if (room[2])
				my_error("wow, 3 room in link");
			free(room[0]);
			free(room[1]);
			free(room);
		}
		i++;
	}
}

void	check_blocks(t_lem *lem)
{
	int i;
	int link;
	int room;

	link = 0;
	room = 0;
	i = 1;
	while (lem->input[i])
	{
		if (is_name(lem->input[i]))
			room = 1;
		if (is_link(lem->input[i]) && !is_comment(lem->input[i]))
			link = 1;
		if (is_name(lem->input[i]) && link)
			my_error("incorrect room/link block");
		if (is_link(lem->input[1]) && !room)
			my_error("incorrect room/link block");
		if (ft_strchr(lem->input[i], ' ') && ft_strchr(lem->input[i], '-') \
			&& !ft_strchr(lem->input[i], '#'))
			my_error("is it link or name?? ");
		i++;
	}
}

void	check_room(t_lem *lem, const char *s)
{
	int		i;
	char	**room;

	i = 1;
	while (lem->input[i])
	{
		if (is_name(lem->input[i]))
		{
			room = ft_strsplit(lem->input[i], ' ');
			free(room[1]);
			free(room[2]);
			if (ft_strequ(room[0], s))
			{
				free(room[0]);
				free(room);
				return ;
			}
			free(room[0]);
			free(room);
		}
		i++;
	}
	my_error("unknown room in link");
}

int		check_start_end(t_lem *lem)
{
	int end_flag;
	int start_flag;
	int i;

	i = 0;
	end_flag = 0;
	start_flag = 0;
	while (lem->input[i])
	{
		if (ft_strequ(lem->input[i], "##start"))
			start_flag++;
		if (ft_strequ(lem->input[i], "##end"))
			end_flag++;
		i++;
	}
	if (start_flag > 1)
		my_error("too many ##start");
	else if (start_flag == 0)
		my_error("no ##start");
	if (end_flag > 1)
		my_error("too many ##end");
	else if (end_flag == 0)
		my_error("no ##end");
	return (1);
}
