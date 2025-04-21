/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:32:07 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/21 19:16:21 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void key_hook(mlx_key_data_t keydata, void *param)
// {
//     t_map *map;

//     map = (t_map *)param;
//     normalize_angle(&map->angl);
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
//         mlx_close_window(map->mlx);
//     if (mlx_is_key_down(map->mlx, MLX_KEY_W) )
//     {
//         map->xp += cos(map->angl)  * 5;
//         map->yp += sin(map->angl) * 5;
//     }
//     if (mlx_is_key_down(map->mlx, MLX_KEY_S))
//     {
//         map->xp -= cos(map->angl) * 5;
//         map->yp -= sin(map->angl) * 5;
//     }
//     if (mlx_is_key_down(map->mlx, MLX_KEY_A))
//     {
//         map->xp += sin(map->angl) * 5;
//         map->yp -= cos(map->angl) * 5;
//     }
//     if (mlx_is_key_down(map->mlx, MLX_KEY_D))
//     {
//         map->xp -= sin(map->angl) * 5;
//         map->yp += cos(map->angl) * 5;
//     }
//     if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
//         map->angl -= 0.1;
//     if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
//         map->angl += 0.1;
//     printf("angle: %f\n", map->angl);
// }


void key_hook(mlx_key_data_t keydata, void *param)
{
    t_map *map = NULL;
    int x;
    int y;

    map = (t_map *)param;
    x = map->xp;
    y = map->yp;
    normalize_angle(&map->angl);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
        mlx_close_window(map->mlx);
    if (mlx_is_key_down(map->mlx, MLX_KEY_W) )
    {
        x += cos(map->angl)  * 5;
        y += sin(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
    {
        x -= cos(map->angl) * 5;
        y -= sin(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
    {
        x += sin(map->angl) * 5;
        y -= cos(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
    {
        x -= sin(map->angl) * 5;
        y += cos(map->angl) * 5;
    }
    if(is_wall(map, x, y, 10))
    {
        map->xp = x;
        map->yp = y;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
        map->angl -= 0.1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->angl += 0.1;
}