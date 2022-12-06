/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:15 by vegret            #+#    #+#             */
/*   Updated: 2022/12/06 17:45:14 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_open(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ", 1);
		ft_putstr_fd(argv[0], 1);
		ft_putendl_fd(" <filename>", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", 1);
		ft_putendl_fd(argv[1], 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/* TODO
Fdf
- abs not from math.h? remove all abs if so
- bresenham propre
- degrade entre les points
- taille de la fenetre adaptative
- centrer la figure
- norme

Makefile
- Message quand ya nothing to do
- Changer les couleurs
*/
int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	vars;

	fd = fdf_open(argc, argv);
	vars.id = NULL;
	vars.img.id = NULL;
	vars.win = NULL;
	init_fdf(fd, &vars);
	put_pixel_img(&vars.img, vars.min.dx, vars.min.dy, 0x00FF0000);
	put_pixel_img(&vars.img, vars.max.dx, vars.max.dy, 0x00FF0000);
	mlx_key_hook(vars.win, &key_listener, &vars);
	mlx_mouse_hook(vars.win, &mouse_listener, &vars);
	mlx_hook(
		vars.win,
		DestroyNotify,
		StructureNotifyMask,
		&destroy_listener,
		&vars);
	mlx_loop(vars.id);
	clean_exit(&vars, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
