//
// Created by Vyacheslav Tretyakov on 03.11.2021.
//
#include "../includes/so_long.h"

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
	int	len;

	len = ft_strlen(map);
	if (!ft_memcmp((map + len - 4), ".ber", 5))
		return (1);
	return (0);
}

char	**parsing(int file, char *file_name)
{
	int		rd;
	int		buf[8];
	int		size;
	char	*str;
	char	**str_split;

	size = 0;
	rd = 1;
	while (rd > 0)
	{
		rd = read(file, buf, 8);
		size += rd;
	}
	str = ft_calloc(size + 1, 1);
	close(file);
	file = open(file_name, O_RDONLY);
	rd = read(file, str, size);
	if (rd != size)
		error_msg("Read error");
	str_split = ft_split(str, '\n');
	free(str);
	return (str_split);
}

int	len_check(char *str[], t_data *img)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[i]) != img->weight)
			return (1);
		i++;
	}
	if (i < 3)
		return (1);
	return (0);
}

int	valid_circuit(char *str[], int str_len, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (i == 0 || i == str_len - 1)
		{
			j = 0;
			while (str[i][j])
			{
				if (str[i][j] != '1')
					return (1);
				j++;
			}
		}
		if (str[i][0] != '1' || str[i][img->weight - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
