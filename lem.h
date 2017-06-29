/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:38:35 by vtymchen          #+#    #+#             */
/*   Updated: 2017/04/27 13:38:38 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "libft/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef	struct s_room	t_room;
typedef	struct s_route	t_route;

struct				s_room
{
	char	*name;
	int		index;
	int		start;
	int		end;
	t_room	*next;
};

struct				s_route
{
	int	*route;
	int	*is_ant_here;
	int	route_len;
};

typedef	struct		s_lem
{
	int		ants;
	int		last_ant;
	t_room	*room_lst;
	int		**matrix;
	int		*used;
	int		*dst;
	int		*prev;
	int		*queue;
	char	**input;
	int		lst_size;
	int		*route;
	t_route	**routes;
}					t_lem;

t_room				*create_room(char *name, int index, int start, int end);
void				print_rooms(t_room *head);
void				reset_all_rooms(t_lem *lem);
void				roomaddend(t_room **room_lst, t_room *room);
void				my_error(const char *s);
void				std_error();
int					check(t_lem *lem);
void				parse(t_lem *lem);
void				print_room(t_room *room);
void				create_all(t_lem *lem);
void				reset_for_bfs(t_lem *lem);
void				push(t_lem *lem, int index);
void				pop(t_lem *lem);
int					front(t_lem *lem);
int					is_empty(t_lem *lem);
void				bfs(t_lem *lem);
void				route(t_lem *lem, int end);
void				print_name(t_lem *lem, int index);
int					get_start(t_lem *lem);
int					get_end(t_lem *lem);
void				find_routes(t_lem *lem);
t_route				*create_route(int *route, t_lem *lem);
void				make_step(t_lem *lem);
void				print(t_lem *lem);
void				go(t_lem *lem);
int					all_in_end(t_lem *lem);
void				make_first_step(t_lem *lem);
int					is_name(const char *s);
int					is_number(const char *s);
int					is_comment(const char *s);
int					is_link(const char *s);
void				init_matrix(t_lem *lem);
void				check_ants(t_lem *lem);
void				check_all(t_lem *lem);
void				check_room_after_start_end(t_lem *lem);
void				check_same(t_lem *lem);
void				check_links(t_lem *lem);
void				check_blocks(t_lem *lem);
void				check_room(t_lem *lem, const char *s);
int					check_start_end(t_lem *lem);
void				check_rooms(t_lem *lem);

#endif
