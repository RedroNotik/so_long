/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:34:46 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/15 15:06:36 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/ghanh/Dev/so_long/includes/so_long.h"

void	move_w(t_data *img, t_char coord)
{
	if (img->map[coord.i - 1][coord.j] != '1')
	{
		if (img->map[coord.i - 1][coord.j] == 'C')
			img->loot->c1++;
		if (img->map[coord.i - 1][coord.j] == 'E')
		{
			img->map[coord.i - 1][coord.j] = 'X';
			img->map[coord.i][coord.j] = '0';
		}
		else
		{
			if (img->map[coord.i][coord.j] == 'X')
				img->map[coord.i][coord.j] = 'E';
			else
				img->map[coord.i][coord.j] = '0';
			img->map[coord.i - 1][coord.j] = 'P';
		}
		draw_map(*img);
	}
}

void	move_a(t_data *img, t_char coord)
{
	if (img->map[coord.i][coord.j - 1] != '1')
	{
		if (img->map[coord.i][coord.j - 1] == 'C')
			img->loot->c1++;
		if (img->map[coord.i][coord.j - 1] == 'E')
		{
			img->map[coord.i][coord.j - 1] = 'X';
			img->map[coord.i][coord.j] = '0';
		}
		else
		{
			if (img->map[coord.i][coord.j] == 'X')
				img->map[coord.i][coord.j] = 'E';
			else
				img->map[coord.i][coord.j] = '0';
			img->map[coord.i][coord.j - 1] = 'P';
		}
		draw_map(*img);
	}
}

void	move_s(t_data *img, t_char coord)
{
	if (img->map[coord.i + 1][coord.j] != '1')
	{
		if (img->map[coord.i + 1][coord.j] == 'C')
			img->loot->c1++;
		if (img->map[coord.i + 1][coord.j] == 'E')
		{
			img->map[coord.i + 1][coord.j] = 'X';
			img->map[coord.i][coord.j] = '0';
		}
		else
		{
			if (img->map[coord.i][coord.j] == 'X')
				img->map[coord.i][coord.j] = 'E';
			else
				img->map[coord.i][coord.j] = '0';
			img->map[coord.i + 1][coord.j] = 'P';
		}
		draw_map(*img);
	}
}

void	move_d(t_data *img, t_char coord)
{
	if (img->map[coord.i][coord.j + 1] != '1')
	{
		if (img->map[coord.i][coord.j + 1] == 'C')
			img->loot->c1++;
		if (img->map[coord.i][coord.j + 1] == 'E')
		{
			img->map[coord.i][coord.j + 1] = 'X';
			img->map[coord.i][coord.j] = '0';
		}
		else
		{
			if (img->map[coord.i][coord.j] == 'X')
				img->map[coord.i][coord.j] = 'E';
			else
				img->map[coord.i][coord.j] = '0';
			img->map[coord.i][coord.j + 1] = 'P';
		}
		draw_map(*img);
	}
}
