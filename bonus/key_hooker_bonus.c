/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:29 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/19 20:26:12 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
													== 'X')
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
		ft_itoa(img->loot->p));
}

void	norma(t_char coord, t_data *img, int keycode)
{
	if (keycode == W || keycode == A1)
		move_w_b(&(*img), coord);
	else if (keycode == A || keycode == A2)
		move_a_b(&(*img), coord);
	else if (keycode == S || keycode == A3)
		move_s_b(&(*img), coord);
	else if (keycode == D || keycode == A4)
		move_d_b(&(*img), coord);
}

int	key_hook(int keycode, t_data *img)
{
	t_char		coord;

	coord = set_player(*img, coord);
	if (keycode == ESC)
		exit(0);
	if (img->loot->winlose == 0)
		norma(coord, img, keycode);
	coord = set_player(*img, coord);
	draw_smth(&(*img));
	if (img->loot->c1 == img->loot->c && img->map[coord.i][coord.j] == 'X')
	{
		mlx_string_put(img->mlx, img->mlx_win, 64 * img->weight / 2, 64, RED,
			"YOU WON!");
		img->loot->winlose = 1;
	}
	if (img->loot->winlose == -1)
		mlx_string_put(img->mlx, img->mlx_win, 64 * img->weight / 2, 64, RED,
			"YOU LOST!");
	return (1);
}
