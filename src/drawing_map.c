//
// Created by Vyacheslav Tretyakov on 03.11.2021.
//
#include "../includes/so_long.h"

char **create_map(int argc, char *argv[])
{
    char    **map;
    int     file;
    if (argc != 2)
        error_msg("Incorrect number of arguments\n");
    if (!check_format(argv[1]))
        error_msg("Incorrect file format\n");
    file = open(argv[1], O_RDONLY);
    if (file < 0)
        error_msg("File problem\n");
    map = parsing(file, argv[1]);
    return (map);
}

void    draw_map(void *mlx, void *mlx_win, t_data img, t_char help)
{
    int x;
    int y;
    int size = 50;

    img.img = mlx_xpm_file_to_image(mlx, "./sprites/floor.xpm", &size, &size);
    while (y < help.height)
    {
        x = 0;
        while (x < help.weight)
        {
            mlx_put_image_to_window(mlx, mlx_win, img.img, x * size, y * size);
            x++;
        }
        y++;
    }
    y = 0;
    img.img = mlx_xpm_file_to_image(mlx, "./sprites/plate.xpm", &size, &size);
    while (y < help.height)
    {
        x = 0;
        while (x < help.weight)
        {
           /* if (img.map[y][x] == '0')
            {}
            else*/ if (img.map[y][x] == '1')
                mlx_put_image_to_window(mlx, mlx_win, img.img, x * size, y * size);
            x++;
        }
        y++;
    }
    //mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 0);
}