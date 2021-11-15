/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:25 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/15 15:13:38 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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

int	main(int argc, char *argv[])
{
	t_char	help;
	t_data	img;

	help = set_null(help, &img);
	errno = 0;
	img.map = create_map(argc, argv);
	strings_check(img.map, &help, &img);
	img.loot = &help;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 64 * img.weight,
			64 * img.height, "So_long");
	mlx_hook(img.mlx_win, 17, 0L, close_game, &img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	draw_map(img);
	mlx_loop(img.mlx);
	ft_free(img.map, img.height);
	return (0);
}
