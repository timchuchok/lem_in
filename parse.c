/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:21:16 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 18:21:19 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	add_in_list(int *i, int *index, t_lem *lem)
{
	char **name;

	if (ft_strequ(lem->input[*i], "##start"))
	{
		*i = *i + 1;
		name = ft_strsplit(lem->input[*i], ' ');
		roomaddend(&lem->room_lst, create_room(name[0], (*index)++, 1, 0));
	}
	else if (ft_strequ(lem->input[*i], "##end"))
	{
		*i = *i + 1;
		name = ft_strsplit(lem->input[*i], ' ');
		roomaddend(&lem->room_lst, create_room(name[0], (*index)++, 0, 1));
	}
	else
	{
		name = ft_strsplit(lem->input[*i], ' ');
		roomaddend(&lem->room_lst, create_room(name[0], (*index)++, 0, 0));
	}
	free(name[0]);
	free(name[1]);
	free(name[2]);
	free(name);
}

static void	parse_rooms(t_lem *lem)
{
	int		i;
	int		index;

	index = 0;
	i = 1;
	lem->ants = ft_atoi(lem->input[0]);
	while (lem->input[i])
	{
		if (ft_strequ(lem->input[i], "##start") || \
		ft_strequ(lem->input[i], "##end") || is_name(lem->input[i]))
			add_in_list(&i, &index, lem);
		else if (is_comment(lem->input[i]))
		{
			i++;
			continue ;
		}
		else
			break ;
		i++;
	}
	lem->lst_size = index;
}

static int	get_index(t_lem *lem, char *name)
{
	t_room *lst;

	lst = lem->room_lst;
	while (lst)
	{
		if (ft_strequ(lst->name, name))
			return (lst->index);
		lst = lst->next;
	}
	return (-1);
}

static void	parse_links(t_lem *lem)
{
	int		i;
	char	**name;

	i = 3;
	while (lem->input[i])
	{
		if (is_link(lem->input[i]) && !is_comment(lem->input[i]))
		{
			name = ft_strsplit(lem->input[i], '-');
			lem->matrix[get_index(lem, name[0])][get_index(lem, name[1])] = 1;
			lem->matrix[get_index(lem, name[1])][get_index(lem, name[0])] = 1;
			free(name[0]);
			free(name[1]);
			free(name);
		}
		i++;
	}
}

void		parse(t_lem *lem)
{
	int i;

	i = 0;
	parse_rooms(lem);
	lem->matrix = (int **)malloc(lem->lst_size * sizeof(int *));
	if (!lem->matrix)
		std_error();
	while (i < lem->lst_size)
	{
		lem->matrix[i] = (int *)malloc(lem->lst_size * sizeof(int));
		if (!lem->matrix[i++])
			std_error();
	}
	init_matrix(lem);
	parse_links(lem);
}
