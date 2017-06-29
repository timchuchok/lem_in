/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:25:35 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 16:25:38 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	delete_link(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->lst_size)
	{
		j = 0;
		while (j < lem->lst_size)
		{
			if (lem->route[i] != -1 && lem->route[j] != -1)
			{
				lem->matrix[lem->route[i]][lem->route[j]] = 0;
				lem->matrix[lem->route[j]][lem->route[i]] = 0;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_lem	*lem;
	int		i;

	if (!(lem = (t_lem *)malloc(sizeof(t_lem))))
		std_error();
	ft_bzero(lem, sizeof(t_lem));
	if (!check(lem))
		return (0);
	parse(lem);
	create_all(lem);
	ft_bzero(lem->routes, sizeof(t_route *) * lem->lst_size);
	find_routes(lem);
	i = 0;
	while (lem->input[i])
		ft_printf("%s\n", lem->input[i++]);
	go(lem);
	return (0);
}

void	find_routes(t_lem *lem)
{
	int flag;

	flag = 0;
	while (1)
	{
		reset_for_bfs(lem);
		lem->prev[get_start(lem)] = -1;
		push(lem, get_start(lem));
		lem->used[get_start(lem)] = 1;
		lem->dst[get_start(lem)] = 0;
		bfs(lem);
		if (lem->dst[get_end(lem)] == -1 && flag == 0)
			my_error("no solution");
		if (lem->dst[get_end(lem)] == -1)
			break ;
		route(lem, get_end(lem));
		delete_link(lem);
		flag++;
	}
}

void	my_error(const char *s)
{
	ft_printf("ERROR: %s\n", s);
	exit(1);
}

void	std_error(void)
{
	perror("Oops");
	exit(1);
}
