/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:32:07 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/19 16:50:19 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_map *map;

    map = (t_map *)param;
    normalize_angle(&map->angl);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
        mlx_close_window(map->mlx);
    if (mlx_is_key_down(map->mlx, MLX_KEY_W) )
    {
        map->xp += cos(map->angl)  * 5;
        map->yp += sin(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
    {
        map->xp -= cos(map->angl) * 5;
        map->yp -= sin(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
    {
        map->xp += sin(map->angl) * 5;
        map->yp -= cos(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
    {
        map->xp -= sin(map->angl) * 5;
        map->yp += cos(map->angl) * 5;
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
        map->angl -= 0.1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->angl += 0.1;
    printf("angle: %f\n", map->angl);
}