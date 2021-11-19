/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:25 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/19 20:20:07 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	t_image_b	sprite;
	t_char		coord;
	int			s;

	sprite = set_src_bonus(sprite);
	coord = set_player(*img, coord);
	img->count++;
	if (img->count < 100)
		stay(img, coord, sprite, s);
	else if (img->count >= 725 && img->count < 750)
		move_right(img, coord, sprite, s);
	else if (img->count >= 300 && img->count < 325)
		move_left(img, coord, sprite, s);
	else if (img->count >= 800 && img->count < 825)
		move_up(img, coord, sprite, s);
	else if (img->count > 825)
		move_down(img, coord, sprite, s);
	else
		img->count = 0;
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
	help.winlose = 0;
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
