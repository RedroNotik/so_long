/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:38:01 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/17 16:45:26 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/ghanh/Dev/so_long/includes/so_long.h"

int	close_game(int keycode, t_data *vars)
{
	exit(EXIT_SUCCESS);
}

t_char	set_player(t_data img, t_char coord)
{
	coord.i = 0;
	coord.j = 0;
	while (img.map[coord.i][coord.j] != 'P'
		&& img.map[coord.i][coord.j] != 'X' )
	{
		coord.j = 0;
		while (coord.j < img.weight)
		{
			if (img.map[coord.i][coord.j] == 'P' || img.map[coord.i][coord.j]
													== 'X' )
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

void	draw_smth(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 20, 40, YELLOW, "Your score:");
	mlx_string_put(img->mlx, img->mlx_win, 140, 40, YELLOW,
		ft_itoa(img->loot->c1));
}

int	key_hook(int keycode, t_data *img)
{
	t_char		coord;

	coord = set_player(*img, coord);
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
	draw_smth(&(*img));
	coord = set_player(*img, coord);
	if (img->loot->c1 == img->loot->c && img->map[coord.i][coord.j] == 'X')
	{
		mlx_string_put(img->mlx, img->mlx_win, 64 * img->weight / 2, 64,
			RED, "YOU WON!");
		mlx_string_put(img->mlx, img->mlx_win, 64 * img->weight / 2 - 64, 80,
			RED, "PRESS ANY KEY TO EXIT");
		mlx_hook(img->mlx_win, 2, 1L << 0, close_game, &(*img));
	}
	return (1);
}
