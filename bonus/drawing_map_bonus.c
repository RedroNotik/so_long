/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:38:36 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/19 20:26:38 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**create_map(int argc, char *argv[])
{
	char	**map;
	int		file;

	if (argc != 2)
		error_msg("Incorrect number of arguments\n");
	if (!check_format(argv[1]))
		error_msg("Incorrect file format\n");
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		error_msg("File problem\n");
	map = parsing(file, argv[1]);
	return (map);
}

t_image_b	set_src_bonus(t_image_b sprite)
{
	sprite.floor = "/Users/ghanh/Dev/so_long/sprites/grass.xpm";
	sprite.food = "/Users/ghanh/Dev/so_long/sprites/seed_1.xpm";
	sprite.enemy = "/Users/ghanh/Dev/so_long/sprites/squirrel.xpm";
	sprite.plate = "/Users/ghanh/Dev/so_long/sprites/bush.xpm";
	sprite.exit = "/Users/ghanh/Dev/so_long/sprites/Houses.xpm";
	sprite.pl = "/Users/ghanh/Dev/so_long/bonus/player.xpm";
	sprite.pl1 = "/Users/ghanh/Dev/so_long/bonus/player1.xpm";
	sprite.pl2 = "/Users/ghanh/Dev/so_long/bonus/player2.xpm";
	sprite.pl3 = "/Users/ghanh/Dev/so_long/bonus/player3.xpm";
	sprite.pl4 = "/Users/ghanh/Dev/so_long/bonus/player4.xpm";
	sprite.pl5 = "/Users/ghanh/Dev/so_long/bonus/player5.xpm";
	sprite.pl6 = "/Users/ghanh/Dev/so_long/bonus/player6.xpm";
	sprite.pl7 = "/Users/ghanh/Dev/so_long/bonus/player7.xpm";
	return (sprite);
}

void	*if_case(t_data img, t_image_b sprite, int x, int y)
{
	int	s;

	s = 64;
	if (img.map[y][x] == '1')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.plate, &s, &s);
	else if (img.map[y][x] == 'C')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.food, &s, &s);
	else if (img.map[y][x] == 'E')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.exit, &s, &s);
	else if (img.map[y][x] == 'S')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.enemy, &s, &s);
	else if (img.map[y][x] == 'X')
	{
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.exit, &s, &s);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img,
			x * s, y * s);
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.pl, &s, &s);
	}
	else if (img.map[y][x] == 'L')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.pl, &s, &s);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * s, y * s);
	return (img.img);
}

void	draw_map(t_data img)
{
	int			x;
	int			y;
	int			s;
	t_image_b	sprite;

	sprite = set_src_bonus(sprite);
	s = 64;
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.weight)
		{
			img.img = mlx_xpm_file_to_image(img.mlx, sprite.floor, &s, &s);
			mlx_put_image_to_window(img.mlx, img.mlx_win, img.img,
				x * s, y * s);
			img.img = if_case(img, sprite, x, y);
			x++;
		}
		y++;
	}
}
