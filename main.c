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
		size += rd;
	}
	str = ft_calloc(size, sizeof(char));
	close(file);
	file = open(file_name, O_RDONLY);
	rd = read(file, str, size);
	if (rd != size)
		error_msg("Read error");
	str_split = ft_split(str, '\n');
	free(str);
	return (str_split);
}

int	len_check(char *str[])
{
	int i;
	int len;

	len = ft_strlen(str[0]);
	i = 1;
	while(str[i])
	{
		if (ft_strlen(str[i]) != len)
			return (1);
		i++;		 
	}
	if (i < 3)
		return (1);
	return (0);
}

int	valid_circuit(char *str[], int str_len)
{
	int i;
	int j;
	int len;

	len = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		if (i == 0 || i == str_len - 1)
		{
			j = 0;
			while(str[i][j])
			{
				if (str[i][j] != '1')
					return (1);
				j++;
			}
		}
		if (str[i][0] != '1' || str[i][len - 1] != '1')
			return (1);
		i++;	
	}
	return (0);
}

t_char set_null(t_char help)
{
	help.i = 0;
	help.j = 0;
	help.c = 0;
	help.e = 0;
	help.p = 0;
	return (help);
}

int	char_check(char *str[])
{
	t_char	help;

	help = set_null(help);
	while(str[help.i])
	{
		help.j = 0;
		while(str[help.i][help.j])
		{
			if (str[help.i][help.j] == 'C')
				help.c++;
			else if (str[help.i][help.j] == 'E')
				help.e++;
			else if (str[help.i][help.j] == 'P')
				help.p++;
			else if (str[help.i][help.j] != '1' && str[help.i][help.j] != '0')
				return (1);	
			help.j++;		
		}
		help.i++;
	}
	if (help.e > 1 || help.p > 1)
		return (1);
	return (0);
}

void	strings_check(char *str[])
{
	int str_len;
	int len;
	int	error_flag;

	str_len = 0;
	while (str[str_len])
		str_len++;
	error_flag = 0;
	error_flag += len_check(str);
	error_flag += valid_circuit(str, str_len);
	error_flag += char_check(str);
	if (error_flag > 0)
	{
		ft_free(str, str_len);
		error_msg("Incorrect map\n");
	}
}

// int	main(int argc, char *argv[])
// {
// 	int		file;
// 	char	**str;

// 	errno = 0;
// 	file = 0;
// 	if (argc != 2)
// 		error_msg("Incorrect number of arguments");
// 	if (!check_format(argv[1]))
// 		error_msg("Incorrect file format");
// 	file = open(argv[1], O_RDONLY);
// 	if (file < 0)
// 		error_msg("File problem");
// 	int i = 0; //todo delete
// 	str = parsing(file, argv[1]);
// 	strings_check(str);
// 	while(str[i]) //todo delete
// 	{
// 		printf("%s and %ld\n", str[i], ft_strlen(str[i]));
// 		i++;
// 	}
// 	return (0);
// }


#include "so_long.h"

int	main(void)
{
	void	*mlx;
	mlx = mlx_init();
}