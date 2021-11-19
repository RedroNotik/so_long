//
// Created by Gaynell Hanh on 11/19/21.
//

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H
# include "so_long.h"

typedef struct s_image_b
{
	char	*floor;
	char	*food;
	char	*plate;
	char	*exit;
	char	*enemy;
	char	*pl;
	char	*pl1;
	char	*pl2;
	char	*pl3;
	char	*pl4;
	char	*pl5;
	char	*pl6;
	char	*pl7;
}				t_image_b;

////drawing map
t_image_b	set_src_bonus(t_image_b sprite);
void		draw_map(t_data img);
char		**create_map(int argc, char *argv[]);
////move_bonus
void		move_up(t_data *img, t_char coord, t_image_b sprite, int s);
void		move_down(t_data *img, t_char coord, t_image_b sprite, int s);
void		move_left(t_data *img, t_char coord, t_image_b sprite, int s);
void		move_right(t_data *img, t_char coord, t_image_b sprite, int s);
void		stay(t_data *img, t_char coord, t_image_b sprite, int s);
////move player bonus
void		move_d_b(t_data *img, t_char coord);
void		move_s_b(t_data *img, t_char coord);
void		move_a_b(t_data *img, t_char coord);
void		move_w_b(t_data *img, t_char coord);
#endif //SO_LONG_SO_LONG_BONUS_H
