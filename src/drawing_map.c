/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:38:36 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/15 15:04:49 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

t_image	set_src(t_image sprite)
{
//	sprite.floor = "./sprites/floor.xpm";
//	sprite.food = "./sprites/foodx.xpm";
//	sprite.human = "./sprites/human.xpm";
//	sprite.plate = "./sprites/plate.xpm";
//	sprite.exit =  "./sprites/squirrel.xpm";
	sprite.floor = "./sprites/grass.xpm";
	sprite.food = "./sprites/seed_1.xpm";
	sprite.human = "./sprites/squirrel.xpm";
	sprite.plate = "./sprites/bush.xpm";
	sprite.exit = "./sprites/Houses.xpm";
	return (sprite);
}

void	*if_case(t_data img, t_image sprite, int x, int y)
{
	int	s;

	s = 64;
	if (img.map[y][x] == '1')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.plate, &s, &s);
	else if (img.map[y][x] == 'C')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.food, &s, &s);
	else if (img.map[y][x] == 'P')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.human, &s, &s);
	else if (img.map[y][x] == 'E')
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.exit, &s, &s);
	else if (img.map[y][x] == 'X')
	{
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.exit, &s, &s);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img,
			x * s, y * s);
		img.img = mlx_xpm_file_to_image(img.mlx, sprite.human, &s, &s);
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * s, y * s);
	return (img.img);
}

void	draw_map(t_data img)
{
	int		x;
	int		y;
	int		s;
	t_image	sprite;

	sprite = set_src(sprite);
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
