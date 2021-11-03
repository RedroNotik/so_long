//
// Created by timof on 01.11.2021.
//

#ifndef SO_LONG_SO_LONG_H
#define SO_LONG_SO_LONG_H

# include "./libft.h"
# include "../mlx/mlx.h"
# include <errno.h> // errno
# include <sys/fcntl.h>
# include <stdio.h> //perror

typedef struct s_char
{
    int c;
    int e;
    int p;
    int i;
    int j;
    int height;
    int weight;
}               t_char;

typedef struct	s_data {
    void	*img;
    char	**map;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

//// parsing
void    error_msg(char *str);
int     check_format(char *map);
char    **parsing(int file, char *file_name);
int     len_check(char *str[], t_char *help);
int     valid_circuit(char *str[], int str_len, t_char *help);
//// parsing_check
int     char_check(char *str[], t_char *help);
void    strings_check(char *str[], t_char *help);
////drawing_map
char    **create_map(int argc, char *argv[]);
void    draw_map(void *mlx, void *mlx_win, t_data img, t_char help);

#endif //SO_LONG_SO_LONG_H
