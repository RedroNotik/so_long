/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:25 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/10 19:57:09 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Created by timof on 01.11.2021.
//

#include "./includes/so_long.h"

t_char	set_null(t_char help, t_data *img)
{
	help.i = 0;
	help.j = 0;
	help.c = 0;
	help.e = 0;
	help.p = 0;
	img->height = 0;
	img->weight = 0;
	return (help);
}

int	move_w(t_data *img, t_char coord)
{
	if (img->map[coord.i - 1][coord.j] != '1')
	{
		img->map[coord.i][coord.j] = '0';
		img->map[coord.i - 1][coord.j] = 'P';
		draw_map(*img);
	}
}

int	move_a(t_data *img, t_char coord)
{
	if (img->map[coord.i][coord.j - 1] != '1')
	{
		img->map[coord.i][coord.j] = '0';
		img->map[coord.i][coord.j - 1] = 'P';
		draw_map(*img);
	}
}

int	move_s(t_data *img, t_char coord)
{
	if (img->map[coord.i + 1][coord.j] != '1')
	{
		img->map[coord.i][coord.j] = '0';
		img->map[coord.i + 1][coord.j] = 'P';
		draw_map(*img);
	}
}

int	move_d(t_data *img, t_char coord)
{
	if (img->map[coord.i][coord.j + 1] != '1')
	{
		img->map[coord.i][coord.j] = '0';
		img->map[coord.i][coord.j + 1] = 'P';
		draw_map(*img);
	}
}

t_char	set_player(t_data img, t_char coord)
{
	coord.i = 0;
	coord.j = 0;
	while (img.map[coord.i][coord.j] != 'P')
	{
		coord.j = 0;
		while (coord.j < img.weight)
		{
			if (img.map[coord.i][coord.j] == 'P')
			{
				coord.i--;
				break ;
			}
			coord.j++;
		}
		coord.i++;
	}
	return (coord);
}

int	key_hook(int keycode, t_data *img)
{
	t_char	coord;

	coord = set_player(*img, coord);
//	printf("Hello from key_hook! %d\n", keycode);
	if (keycode == ESC)
		exit(0);
	else if (keycode == W || keycode == A1)
		move_w(&(*img), coord);
	else if (keycode == A || keycode == A2)
		move_a(&(*img), coord);
	else if (keycode == S || keycode == A3)
		move_s(&(*img), coord);
	else if (keycode == D || keycode == A4)
		move_d(&(*img), coord);
}

int	main(int argc, char *argv[])
{
	t_char	help;
	t_data	img;

	help = set_null(help, &img);
	errno = 0;
	img.map = create_map(argc, argv);
	strings_check(img.map, &help, &img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 50 * img.weight, 50 * img.height,
							 "So_long"); //// todo set to 64
	mlx_key_hook(img.mlx_win, key_hook, &img);
	draw_map(img);
	mlx_loop(img.mlx);
	ft_free(img.map, img.height);
	return (0);
}
