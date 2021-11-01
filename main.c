//
// Created by timof on 01.11.2021.
//

#include "./includes/so_long.h"
#include <stdio.h> //todo delete

void	error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(EXIT_FAILURE);
}

int	check_format(char *map)
{
	int len;

	len = ft_strlen(map);
	if (!ft_memcmp((map + len - 4), ".ber", 5))
		return (1);
	return (0);
}

char **parsing(int file, char *file_name)
{
	int		rd;
	int		buf[8];
	int		size;
	char	*str;
	char	**str_split;
	size = 0;
	rd = 1;
	while(rd > 0)
	{
		rd = read(file, buf, 10);
	//	printf("Sizerd = %d\n", rd);
		size += rd;
	}
	printf("SSize = %d\n", size);
	str = ft_calloc(size, sizeof(char));
	close(file);
	file = open(file_name, O_RDONLY);
	rd = read(file, str, size);
	printf("Size = %d\n", rd);
	if (rd != size)
		printf("FAIL %d and %d\n", rd, size);
	str_split = ft_split(str, '\n');
	return (str_split);
}

int	main(int argc, char *argv[])
{
	int file;

	errno = 0;
	file = 0;
	if (argc != 2)
		error_msg("Incorrect number of arguments");
	if (!check_format(argv[1]))
		error_msg("Incorrect file format");
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		error_msg("File problem");
	int i = 0;
	char **str = parsing(file, argv[1]);
	while(str[i])
	{
		printf("%s and %d\n", str[i], ft_strlen(str[i]));
		i++;
	}
	return (0);
}