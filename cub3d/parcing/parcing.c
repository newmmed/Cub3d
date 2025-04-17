/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:06:08 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/15 12:51:50 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void affect_int(char *str, int *tab)
{
	char **split;
	int i;

	i = 0;
	while(str[i])
	{
		if((str[i] < '0' || str[i] > '9') &&
			str[i] != ' ' && str[i] != ',' && ft_strlen(str) - 1 != i)
		{
			write_err("Error\nbad colors\n");
			exit(1);
		}
		i++;
	}
	split = multi_split(str, ", \n");

	printf("leen array %d\n", size_array(split));
	// printf("leen zzzzz '%c'\n", split[2][0]);
	if(size_array(split) == 3)
	{
		tab[0] = ft_atoi(split[0], 255);
		tab[1] = ft_atoi(split[1], 255);
		tab[2] = ft_atoi(split[2], 255);
		if(tab[0] == -1 || tab[1] == -1 || tab[2] == -1)
		{
			write_err("Error\nbad colors\n");
			exit(1);
		}
	}
	else
	{
		free2(split);
		write_err("Error\nbad colors\n");
		exit(1);
	}
	free2(split);
}

// int comp(char *str, int *nbr, t_map *map)
// {
// 	if(!ft_strncmp(str,"NO",2) && !map->NO)
// 		map->NO = ft_strdup(str + 3);// add trim trim(ft_strdup(str + 3))
// 	else if(!ft_strncmp(str,"SO",2) && !map->SO)
// 		map->SO = ft_strdup(str + 3);
// 	else if(!ft_strncmp(str,"WE",2) && !map->WE)
// 		map->WE = ft_strdup(str + 3);
// 	else if(!ft_strncmp(str,"EA",2) && !map->EA)
// 		map->EA = ft_strdup(str + 3);
// 	else if(!ft_strncmp(str,"F ",2) && map->F[0] == -1)
// 		affect_int(str + 2, map->F);
// 	else if(!ft_strncmp(str,"C ",2) && map->C[0] == -1)
// 		affect_int(str + 2, map->C);
// 	else if(ft_strncmp(str,"\n",1))
// 		return(write_err("Error\nbad Elements\n"),1);
// 	else if(!ft_strncmp(str,"\n",1))
// 		return(0);
// 	(*nbr)++;
// 	return(0);
// }

int comp(char *str, int *nbr, t_map *map)
{
	if(!ft_strncmp(str,"NO",2) && !map->NO)
		map->NO = ft_strtrim(ft_strdup(str + 3), " \n");// add trim trim(ft_strdup(str + 3))
	else if(!ft_strncmp(str,"SO",2) && !map->SO)
		map->SO = ft_strtrim(ft_strdup(str + 3), " \n");
	else if(!ft_strncmp(str,"WE",2) && !map->WE)
		map->WE = ft_strtrim(ft_strdup(str + 3), " \n");
	else if(!ft_strncmp(str,"EA",2) && !map->EA)
		map->EA = ft_strtrim(ft_strdup(str + 3), " \n");
	else if(!ft_strncmp(str,"F ",2) && map->F[0] == -1)
		affect_int(str + 2, map->F);
	else if(!ft_strncmp(str,"C ",2) && map->C[0] == -1)
		affect_int(str + 2, map->C);
	else if(ft_strncmp(str,"\n",1))
		return(write_err("Error\nbad Elements\n"),1);
	else if(!ft_strncmp(str,"\n",1))
		return(0);
	(*nbr)++;
	return(0);
}

void    read_part1(int fd, t_map *map)
{
	char *line;
	int nbr;

	nbr = 0;
	line = get_next_line(fd);
	if (!line || !line[0])
	{
		write_err("empty file\n");
		exit(1);
	}
	while(line)
	{
		if (comp(line, &nbr, map))
			exit(1);// a verifier
		free(line);
		if (nbr == 6)
			break;
		line = get_next_line(fd);
	}
	if(nbr != 6)
	{
		write_err("Error\nbad Elements\n");
		exit(1);
	}
}

double angl(char c)
{
	if(c == 'N')
		return(3 * M_PI_2);
	else if(c == 'E')
		return(0);
	else if(c == 'W')
		return(M_PI);
	else if(c == 'S')
		return(M_PI_2);
	return(0);
}
void is_valid(char *line, int i, t_map *map)
{
	int j;

	j = 0;
	while(line[j])
	{
		if(!ft_strchr("10 NEWS\n",line[j]))//je pense je dois verifier \n
		{
			write_err("Error\nbad map Element\n");
			exit(1);
		}
		if(ft_strchr("NEWS",line[j]) && map->xp != -1)
		{
			write_err("Error\nmore than one player\n");
			exit(1);
		}
		else if(ft_strchr("NEWS",line[j]) && map->xp == -1)
		{
			map->xp = j * TILESIZE + TILESIZE / 2;
			map->yp = i * TILESIZE + TILESIZE / 2;
			map->angl = angl(line[j]);
		}
		j++;
	}
}

void val_position(char **scene, int i)
{
	int j;

	j = 0;
	while(scene[i][j])
	{
		if(i == 0 || i == size_array(scene) - 1 || j == 0 || j == ft_strlen(scene[i]) - 1)
		{
			if(!ft_strchr("1 ",scene[i][j]))
			{
				write_err("Error\nThe perimeter of the scene must not contain only 1s and spaces.\n");
				exit(1);
			}
		}
		else if(scene[i][j] == '0' || ft_strchr("NEWS", scene[i][j]))
		{
			if((j >= ft_strlen(scene[i-1]) || scene[i - 1][j] == ' ') || 
				(j >= ft_strlen(scene[i + 1]) || scene[i + 1][j] == ' ') ||\
				(scene[i][j - 1] == ' ') || (scene[i][j + 1] == ' '))
			{
				write_err("Error\nThere should be no 0s around the space\n");
				exit(1);
			}
		}
		j++;
	}
}
void check_map(t_map *map)
{
	int i;

	i = 0;
	while(map->map[i])
	{
		is_valid(map->map[i], i, map);// in this case i think i dont need to return
		val_position(map->map, i);// in this case i think i dont need to return
		i++;
	}
	//check if player not exist print error
	if(map->xp == -1)
	{
		write_err("Error\nThere is no player, you need to set one.\n");
			exit(1);
	}
}

void read_part2(int fd, t_map *map)
{
	char *line;
	char *count;
	int j;
	

	j = 0;
	count = ft_strdup("");
	line = get_next_line(fd);
	if (!line || !line[0])
	{
		write_err("empty file\n");
		exit(1);
	}
	while(!ft_strcmp(line,"\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	// verifier est ce que je dois lire une autre fois ou nn
	// read_map(fd);
	while(line)
	{
		count = ft_strjoin(count, line, 1);
		free(line);
		line = get_next_line(fd);
		if(!ft_strcmp(count + ft_strlen(count) - 2, "\n\n"))// je peut la changer avec strncmp
		{
			write_err("Error\nbad map\n");
			exit(1);
		}
	}
	map->map = multi_split(count, "\n");
	check_map(map);
}

void check_path(t_map *map)
{
	int fd;

	if((fd = open(map->EA, O_RDONLY)) < 0)
	{
		write_err("Error\ninvalid path\n");
		exit(1);
	}
	close(fd);
	if((fd = open(map->WE, O_RDONLY)) < 0)
	{
		write_err("Error\ninvalid path\n");
		exit(1);
	}
	close(fd);
	if((fd = open(map->SO, O_RDONLY)) < 0)
	{
		write_err("Error\ninvalid path\n");
		exit(1);
	}
	close(fd);
	if((fd = open(map->NO, O_RDONLY)) < 0)
	{
		write_err("Error\ninvalid path\n");
		exit(1);
	}
	close(fd);
}
void input(char *str, t_map *map)
{
	int fd;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return(write_err("Error\nFailed to open file\n"));
	read_part1(fd, map);
	read_part2(fd, map);
	printf("[%s]\n",map->NO);
	printf("]%s]\n",map->SO);
	printf("[%s]\n",map->WE);
	check_path(map);
}
