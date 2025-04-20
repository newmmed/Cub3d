/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:09:39 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/20 23:04:51 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_map *map, double ax, double ay)
{
	int i;
	int j;

    i = (ay / TILESIZE);
    j = (ax / TILESIZE);
    if (i < 0 || j < 0  || i >= size_array(map->map) || j >= ft_strlen(map->map[i]))
		return (0);
	if (map->map[i][j] == '1')
		return (0);
    j = (ax - 0.1) / TILESIZE ;
	if (j > 0 && map->map[i][j] == '1')
		return (0);
    j = (ax + 0.1)/ TILESIZE;
	if (j + 1 < ft_strlen(map->map[i]) && map->map[i][j] == '1')
		return (0);
    i = (ay - 0.1)/ TILESIZE;
	if (i > 0 && map->map[i][j] == '1')
		return (0);
    i = (ay  + 0.1)/ TILESIZE;
	if (i + 1 < size_array(map->map) && map->map[i][j] == '1')
		return (0);
	return (1);
}

t_ray horiz_intersect(t_map *map, double angle)
{
    double ax;
    double ay;
    double addx;
    double addy;
    t_ray ray;
    
    ray.horiz = 1;
    if(angle >= 0 && angle <= M_PI)
    {
        ay = (map->yp / TILESIZE + 1)* TILESIZE ;
        addx =  TILESIZE / tan(angle);
        addy = TILESIZE;
    }
    else
    {
        ay = (map->yp / TILESIZE * TILESIZE) - 0.1;
        addx = -TILESIZE / tan(angle);
        addy = -TILESIZE;
    }
    ax = ((ay - map->yp) / tan(angle)) + map->xp;
    while(1)
    {
        if(!is_wall(map, ax, ay))
            break;
        ax += addx;
        ay += addy;
    }
    ray.distance = sqrt((ax - map->xp) * (ax - map->xp) + (ay - map->yp) * (ay - map->yp));
    ray.pos_in_tile_x = ax - (int)(ax / TILESIZE) * TILESIZE;
    ray.pos_in_tile_y = ay - (int)(ay / TILESIZE) * TILESIZE;
    
    return(ray);
}
t_ray vertic_intersect(t_map *map, double angle)
{
    double ax;
    double ay;
    double addx;
    double addy;
    t_ray ray;

    ray.vert = 1;
    if(angle >= M_PI_2 && angle <= 3 * M_PI_2)
    {
        ax = ((map->xp / TILESIZE) * TILESIZE) - 0.1;
        addy = -TILESIZE * tan(angle);
        addx = -TILESIZE;
    }
    else
    {
        ax = ((map->xp / TILESIZE) + 1) * TILESIZE ;
        addy =  TILESIZE * tan(angle);
        addx = TILESIZE;
    }
    ay = ((ax - map->xp) * tan(angle)) + map->yp;
    while(1)
    {
        if(!is_wall(map, ax, ay))
            break;
        ax += addx;
        ay += addy;
    }
    ray.distance = sqrt((ax - map->xp) * (ax - map->xp) + (ay - map->yp) * (ay - map->yp));
    ray.pos_in_tile_x = ax - (int)(ax / TILESIZE) * TILESIZE;
    ray.pos_in_tile_y = ay - (int)(ay / TILESIZE) * TILESIZE;
    
    return(ray);
}