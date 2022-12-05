/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:17:51 by vegret            #+#    #+#             */
/*   Updated: 2022/12/05 17:01:56 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pointsclear(t_points **lst)
{
	t_points	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	lstiter(t_points *lst, void (*f)(t_point *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(&lst->data);
		lst = lst->next;
	}
}

t_points	*new_point(int x, int y)
{
	t_points	*new;

	new = malloc(sizeof(t_points));
	if (!new)
		return (NULL);
	new->data.x = x;
	new->data.y = y;
	new->data.z = 0;
	new->data.dx = x;
	new->data.dy = y;
	new->data.color = DEFAULT_POINT_COLOR;
	new->next = NULL;
	return (new);
}

char	*uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

void	clean_exit(t_vars *vars, int status)
{
	if (vars)
	{
		if (vars->points)
			pointsclear(&vars->points);
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->mlx)
			mlx_destroy_display(vars->mlx);
		if (vars->mlx)
			free(vars->mlx);
	}
	exit(status);
}
