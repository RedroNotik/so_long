/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:34:46 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/19 20:17:11 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//void lost_game(t_data *img)
//{
////
//}
//		if (img->map[coord.i - 1][coord.j] == 'S')
//			img->loot->win_lose = 1;

void	move_w_b(t_data *img, t_char coord)
{
	img->count = 800;
	if (img->map[coord.i - 1][coord.j] != '1')
	{
		++img->loot->p;
		if (img->map[coord.i - 1][coord.j] == 'C')
			img->loot->c1++;
		if (img->map[coord.i - 1][coord.j] == 'S')
			img->loot->winlose = -1;
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

void	move_a_b(t_data *img, t_char coord)
{
	img->count = 300;
	if (img->map[coord.i][coord.j - 1] != '1')
	{
		++img->loot->p;
		if (img->map[coord.i][coord.j - 1] == 'C')
			img->loot->c1++;
		if (img->map[coord.i][coord.j - 1] == 'S')
			img->loot->winlose = -1;
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

void	move_s_b(t_data *img, t_char coord)
{
	img->count = 825;
	if (img->map[coord.i + 1][coord.j] != '1')
	{
		++img->loot->p;
		if (img->map[coord.i + 1][coord.j] == 'C')
			img->loot->c1++;
		if (img->map[coord.i + 1][coord.j] == 'S')
			img->loot->winlose = -1;
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

void	move_d_b(t_data *img, t_char coord)
{
	img->count = 725;
	if (img->map[coord.i][coord.j + 1] != '1')
	{
		++img->loot->p;
		if (img->map[coord.i][coord.j + 1] == 'C')
			img->loot->c1++;
		if (img->map[coord.i][coord.j + 1] == 'S')
			img->loot->winlose = -1;
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
