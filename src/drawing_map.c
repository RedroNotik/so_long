//
// Created by Vyacheslav Tretyakov on 03.11.2021.
//
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
	sprite.floor = "./sprites/floor.xpm";
	sprite.food = "./sprites/foodx.xpm";
	sprite.human = "./sprites/human.xpm";
	sprite.plate = "./sprites/plate.xpm";
	return (sprite);
}

void	draw_map(t_data img)
{
	int		x;
	int		y;
	int		size;
	t_image	sprite;

	sprite = set_src(sprite);
	size = 50; //todo set 64
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.weight)
		{
			img.img = mlx_xpm_file_to_image(img.mlx, sprite.floor, &size,
											&size);
			mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * size, y *
			size);
			if (img.map[y][x] == '1')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, sprite.plate, &size,&size);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x *
				size, y * size);
			}
			else if (img.map[y][x] == 'C')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, sprite.food, &size,&size);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * size, y * size);
			}
			else if (img.map[y][x] == 'P')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, sprite.human, &size,&size);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * size, y * size);
			}
			else if (img.map[y][x] == 'E')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, sprite.food, &size,
												&size); //todo change exit
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, x * size,
										y * size);
			}
			x++;
		}
		y++;
	}
}