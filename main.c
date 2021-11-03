//
// Created by timof on 01.11.2021.
//

#include "./includes/so_long.h"

t_char set_null(t_char help)
{
	help.i = 0;
	help.j = 0;
	help.c = 0;
	help.e = 0;
	help.p = 0;
    help.height = 0;
    help.weight = 0;
	return (help);
}

 int	main(int argc, char *argv[])
 {
    // char   **map;
     t_char help;
     void   *mlx;
     void   *mlx_win;
     t_data img;

    help = set_null(help);
 	errno = 0;
    img.map = create_map(argc, argv);
 	strings_check(img.map, &help);
     mlx = mlx_init();
     mlx_win = mlx_new_window(mlx, 50 * help.weight, 50 * help.height, "So_long");
     draw_map(mlx, mlx_win, img, help);
    // mlx_string_put(mlx, mlx_win,20, 20, 255, "Slava hello");
//     void	*mlx;
//     void	*mlx_win;
//     t_data	img;
//
//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//                                  &img.endian);
//     my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
     mlx_loop(mlx);
     ft_free(img.map, help.height);
 	return (0);
 }
