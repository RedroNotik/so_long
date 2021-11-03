//
// Created by Vyacheslav Tretyakov on 03.11.2021.
//
#include "../includes/so_long.h"

int	char_check(char *str[], t_char *help)
{
    while(str[help->i])
    {
        help->j = 0;
        while(str[help->i][help->j])
        {
            if (str[help->i][help->j] == 'C')
                help->c++;
            else if (str[help->i][help->j] == 'E')
                help->e++;
            else if (str[help->i][help->j] == 'P')
                help->p++;
            else if (str[help->i][help->j] != '1' && str[help->i][help->j] != '0')
                return (1);
            help->j++;
        }
        help->i++;
    }
    if (help->e < 1 || help->p < 1 || help->c < 1)
        return (1);
    return (0);
}

void	strings_check(char *str[], t_char *help)
{
    int	error_flag;

    while (str[help->height])
        help->height++;
    help->weight = ft_strlen(str[0]);
    error_flag = 0;
    error_flag += len_check(str, help);
    error_flag += valid_circuit(str, help->height, help);
    error_flag += char_check(str, help);
    if (error_flag > 0)
    {
        ft_free(str, help->height);
        error_msg("Incorrect map\n");
    }
}