/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanh <ghanh@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:04:16 by ghanh             #+#    #+#             */
/*   Updated: 2021/11/10 19:39:04 by ghanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define A1 126
# define A2 123
# define A3 125
# define A4 124

# include "./libft.h"
# include "../mlx/mlx.h"
# include <errno.h> // errno
# include <sys/fcntl.h>
# include <stdio.h> //perror

typedef struct s_char
{
	int	c;
	int	e;
	int	p;
	int	i;
	int	j;
}			t_char;

typedef struct s_data
{
	void	*img;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		weight;
}				t_data;

typedef struct s_image
{
	char	*floor;
	char	*human;
	char	*food;
	char	*plate;
}				t_image;

//// parsing
void	error_msg(char *str);
int		check_format(char *map);
char	**parsing(int file, char *file_name);
int		len_check(char *str[], t_data *img);
int		valid_circuit(char *str[], int str_len, t_data *img);
//// parsing_check
int		char_check(char *str[], t_char *help);
void	strings_check(char *str[], t_char *help, t_data *img);
////drawing_map
char	**create_map(int argc, char *argv[]);
void	draw_map(t_data img);

#endif //SO_LONG_SO_LONG_H
