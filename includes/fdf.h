/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:56 by vegret            #+#    #+#             */
/*   Updated: 2022/11/26 00:50:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MLX_WIDTH 800
# define MLX_HEIGHT 600
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include "libft.h"
# include "mlx.h"

/*
x: Line
y: Column
z: Height
*/
typedef struct s_point {
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_point;

typedef struct s_points {
	t_point			content;
	struct s_points	*next;
}				t_points;

t_points	*parse_map(int fd);
t_points	*new_point(int x, int y);
char		*uppercase(char *str);
void		pointsclear(t_points **lst);

#endif