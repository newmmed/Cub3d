/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:06:05 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/21 00:27:45 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void write_err(char *str)
{
    write(2, str, ft_strlen(str));
}

void init_map(t_map *map)
{
    map->EA = NULL;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
    map->C[0] = -1;
    map->F[0] = -1;
    map->xp = -1;
    map->yp = -1;
    map->angl = -1;
}

void ll ()// deleted it
{
    printf("----------------\n");
    system("leaks -q a.out");
}

int main(int argc, char **argv)
{
    // atexit(ll);
    t_map map;
    if(argc != 2 || ft_strlen(argv[1]) <= 4 || \
        ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
        return(write_err("Error\nUsage: ./cub3d <map.cub>\n"), 1);
    init_map(&map);
    input(argv[1], &map);
    map.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
    if (!map.mlx)
    {
			write_err("Error\nFailed to initialize MLX\n");
			exit(1);
	}
    // draw_map(&map);
    
	

	// Try to load the file
	map.tex_ea = mlx_load_png(map.EA);
    map.tex_no = mlx_load_png(map.NO);
    map.tex_so = mlx_load_png(map.SO);
    map.tex_we = mlx_load_png(map.WE);
	if (!map.tex_ea || !map.tex_no || !map.tex_so || !map.tex_we)
        return(1);
        
    mlx_key_hook(map.mlx, key_hook, &map);
    mlx_loop_hook(map.mlx, draw_map, &map);
    mlx_loop(map.mlx);
    return(0);
}



