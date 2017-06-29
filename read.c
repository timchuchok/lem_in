/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:11:34 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 21:11:38 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	void	read_in(t_lem *lem)
{
	char	*line;
	char	*input;

	input = ft_strdup("");
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '\0')
			my_error("empty line");
		input = ft_strjoin(input, line);
		input = ft_strjoin(input, "\n");
		free(line);
	}
	if (ft_strlen(input) > 0)
	{
		if (input[ft_strlen(input) - 1] == '\n')
			input[ft_strlen(input) - 1] = '\0';
		lem->input = ft_strsplit(input, '\n');
		free(input);
	}
}

static	void	check_coord(t_lem *lem)
{
	int		i;
	char	**split;

	i = 1;
	while (lem->input[i])
	{
		if (is_name(lem->input[i]))
		{
			split = ft_strsplit(lem->input[i], ' ');
			if (!split[0])
				my_error("oops");
			if (!split[1])
				my_error("no coord");
			if (!split[2])
				my_error("no coord");
			if (!is_number(split[1]) || !is_number(split[2]) || split[3])
				my_error("incorrect coord");
			free(split[0]);
			free(split[1]);
			free(split[2]);
			free(split);
		}
		i++;
	}
}

static void		check_rooms_in_link(t_lem *lem)
{
	int		i;
	char	**rooms;

	i = 1;
	while (lem->input[i])
	{
		if (is_link(lem->input[i]) && !is_comment(lem->input[i]))
		{
			rooms = ft_strsplit(lem->input[i], '-');
			check_room(lem, rooms[0]);
			check_room(lem, rooms[1]);
			free(rooms[0]);
			free(rooms[1]);
			free(rooms);
		}
		i++;
	}
}

static void		check_def(t_lem *lem)
{
	int i;
	int j;
	int flag;

	i = 1;
	while (lem->input[i])
	{
		if (is_link(lem->input[i]) && !is_comment(lem->input[i]))
		{
			j = 0;
			flag = 0;
			while (lem->input[i][j])
			{
				if (lem->input[i][j] == '-')
					flag++;
				j++;
			}
			if (flag > 1)
				my_error("to many \'-\'");
		}
		i++;
	}
}

int				check(t_lem *lem)
{
	read_in(lem);
	if (!lem->input)
		my_error("empty file");
	check_ants(lem);
	check_start_end(lem);
	check_room_after_start_end(lem);
	check_coord(lem);
	check_same(lem);
	check_all(lem);
	check_links(lem);
	check_blocks(lem);
	check_rooms_in_link(lem);
	check_rooms(lem);
	check_def(lem);
	return (1);
}
