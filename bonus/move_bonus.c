/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:55:01 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/19 17:55:08 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_data *img, t_char coord, t_image_b sprite, int s)
{
	if (img->count > 825)
		img->count = 0;
	else if (img->count / 6 % 2 == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl2, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl3, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
}

void	move_down(t_data *img, t_char coord, t_image_b sprite, int s)
{
	if (img->count > 850)
		img->count = 0;
	else if (img->count / 6 % 2 == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl1, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
}

void	stay(t_data *img, t_char coord, t_image_b sprite, int s)
{
	if (img->count == 100)
		img->count = 0;
	else if (img->count < 50)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl4, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl5, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
}

void	move_right(t_data *img, t_char coord, t_image_b sprite, int s)
{
	if (img->count > 751)
		img->count = 0;
	else if (img->count / 6 % 2 == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl4, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl5, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
}

void	move_left(t_data *img, t_char coord, t_image_b sprite, int s)
{
	if (img->count > 325)
		img->count = 0;
	else if (img->count / 6 % 2 == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl6, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
	else
	{
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.floor, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
		img->img = mlx_xpm_file_to_image(img->mlx, sprite.pl7, &s, &s);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			coord.j * 64, coord.i * 64);
	}
}
