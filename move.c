/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:31:36 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 16:31:39 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		go(t_lem *lem)
{
	lem->last_ant = 1;
	while (!all_in_end(lem))
	{
		print(lem);
		make_step(lem);
	}
}

void		make_step(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->routes[i] && i < lem->lst_size)
	{
		j = lem->routes[i]->route_len - 1;
		while (j != 0)
		{
			lem->routes[i]->is_ant_here[j] = lem->routes[i]->is_ant_here[j - 1];
			lem->routes[i]->is_ant_here[j - 1] = 0;
			j--;
		}
		i++;
	}
	make_first_step(lem);
}

void		make_first_step(t_lem *lem)
{
	int i;

	i = 0;
	if (lem->ants)
	{
		while (lem->routes[i] && i < lem->lst_size)
		{
			if (lem->routes[i]->route_len -  \
				lem->routes[0]->route_len < lem->ants && lem->ants)
			{
				lem->routes[i]->is_ant_here[1] = lem->last_ant++;
				if (lem->ants)
					lem->ants--;
			}
			i++;
		}
	}
}

static void	print_first(t_lem *lem)
{
	int i;

	i = 0;
	while (lem->routes[i] && i < lem->lst_size)
	{
		if (lem->routes[i]->is_ant_here[1])
		{
			ft_printf("L%i-", lem->routes[i]->is_ant_here[1]);
			print_name(lem, lem->routes[i]->route[1]);
			ft_printf(" ");
		}
		i++;
	}
	ft_printf("\n");
}

void		print(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->routes[i] && i < lem->lst_size)
	{
		j = lem->routes[i]->route_len - 1;
		while (j > 1)
		{
			if (lem->routes[i]->is_ant_here[j])
			{
				ft_printf("L%i-", lem->routes[i]->is_ant_here[j]);
				print_name(lem, lem->routes[i]->route[j]);
				ft_printf(" ");
			}
			j--;
		}
		i++;
	}
	print_first(lem);
}
