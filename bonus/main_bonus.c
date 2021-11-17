//
// Created by Gaynell Hanh on 11/17/21.
//

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:25 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/17 16:51:19 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_char	set_null(t_char help, t_data *img)
{
	help.i = 0;
	help.j = 0;
	help.c = 0;
	help.e = 0;
	help.p = 0;
	help.c1 = 0;
	img->height = 0;
	img->weight = 0;
	return (help);
}

int	name_func(t_data *img)
{
	t_image	sprite;
	int s;
	sprite = set_src(sprite);
	img->count++;
//	if (img->count == 200)
//	{
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate2, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//	}
//	else if (img->count == 400)
//	{
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//	}
//	else if (img->count == 600)
//	{
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate2, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//	}
//	else if (img->count == 700)
//	{
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//	}
//	else if (img->count == 800)
//	{
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate2, &s, &s);
//		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
//								0, 0);
//	}
	if (img->count % 500 == 1)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
								0, 0);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
								0, 0);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
								0, 0);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.plate2, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
								0, 0);
		img->count = 0;
	}
	return (0);
}
int	main(int argc, char *argv[])
{
	t_char	help;
	t_data	img;

	help = set_null(help, &img);
	errno = 0;
	img.map = create_map(argc, argv);
	strings_check(img.map, &help, &img);
	help.p = 0;
	img.loot = &help;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 64 * img.weight,
								 64 * img.height, "So_long");
	mlx_hook(img.mlx_win, 17, 0L, close_game, &img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	draw_map(img);
	mlx_loop_hook(img.mlx, name_func, &img);
	mlx_loop(img.mlx);
	ft_free(img.map, img.height);
	return (0);
}
