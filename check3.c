/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:17:10 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 21:17:13 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	cmp_room(t_lem *lem, int j, char **room)
{
	char **check;

	while (lem->input[j])
	{
		if (is_name(lem->input[j]))
		{
			check = ft_strsplit(lem->input[j], ' ');
			if (ft_strequ(check[0], room[0]))
			{
				my_error("same room");
			}
			if (ft_strequ(check[1], room[1]) && ft_strequ(check[2], room[2]))
				my_error("same coords");
			free(check[0]);
			free(check[1]);
			free(check[2]);
			free(check);
		}
		j++;
	}
}

void		check_rooms(t_lem *lem)
{
	int		i;
	int		j;
	char	**room;

	i = 1;
	while (lem->input[i])
	{
		if (is_name(lem->input[i]))
		{
			j = i + 1;
			room = ft_strsplit(lem->input[i], ' ');
			cmp_room(lem, j, room);
			free(room[0]);
			free(room[1]);
			free(room[2]);
			free(room);
		}
		i++;
	}
}
