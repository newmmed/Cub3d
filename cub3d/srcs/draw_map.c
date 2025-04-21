/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:03:53 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/21 19:01:10 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_square(t_map *map, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while(i < TILESIZE)
    {
        j = 0;
        while(j < TILESIZE)
        {
            mlx_put_pixel(map->img, x * TILESIZE + j, y * TILESIZE + i, color);
            j++;
        }
        i++;
    }
}

// void draw_ray(t_map *map, double px, double py, double dx, double dy, int color)
// {
//     double ray_x = px;
//     double ray_y = py;

//     // calcul de la distance totale entre les deux points
//     double distance = sqrt((dx - px) * (dx - px) + (dy - py) * (dy - py));

//     // calcul du pas pour aller d’un point à l’autre
//     double step_x = (dx - px) / distance;
//     double step_y = (dy - py) / distance;

//     int step = 0;
//     while (step < (int)distance)
//     {
//         if (ray_x >= 0 && ray_y >= 0 && ray_x < WIDTH && ray_y < HEIGHT)
//             mlx_put_pixel(map->img, (int)ray_x, (int)ray_y, color);
//         ray_x += step_x;
//         ray_y += step_y;
//         step++;
//     }
// }


void draw_ray(t_map *map, double px, double py, double angle, double distance, int color)
{
    double dx = px + cos(angle) * distance;
    double dy = py + sin(angle) * distance;

    double ray_x = px;
    double ray_y = py;

    // calcul du pas pour aller d’un point à l’autre
    double step_x = (dx - px) / distance;
    double step_y = (dy - py) / distance;

    int step = 0;
    while (step < (int)distance)
    {
        if (ray_x >= 0 && ray_y >= 0 && ray_x < WIDTH && ray_y < HEIGHT)
            mlx_put_pixel(map->img, (int)ray_x, (int)ray_y, color);
        ray_x += step_x;
        ray_y += step_y;
        step++;
    }
}

void normalize_angle(double *angle)
{
    if (*angle < 0)
        *angle += 2 * M_PI;
    if (*angle >= 2 * M_PI)
        *angle -= 2 * M_PI;
}

static int	color(int *arr)
{
	return ((arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | 0xFF);
}
void draw_C_F(t_map *map)
{
    int i;
    int j;

    i = 0;
    while(i < HEIGHT)
    {
        j = 0;
        while(j < WIDTH)
        {
            if (i < HEIGHT / 2)
                mlx_put_pixel(map->img, j, i, color(map->C));
            else
                mlx_put_pixel(map->img, j, i, color(map->F));
            j++;
        }
        i++;
    }
}
void draw_all_rays(t_map *map)
{
    // t_ray rays[WIDTH];
    double angle;
    int i;
    double line_height;
    double begin;
    double end;
    double corrected_distance;

    i = 0;
        normalize_angle(&map->angl);
    angle = map->angl - (FOV / 2);
    draw_C_F(map);
    while(i < WIDTH)
    {
        normalize_angle(&angle);
        if ((horiz_intersect(map, angle)).distance < (vertic_intersect(map, angle)).distance)
        {
            corrected_distance = (horiz_intersect(map, angle)).distance * cos(angle - map->angl);
            line_height = (TILESIZE / corrected_distance) * WIDTH;
        }
        else
        {
            corrected_distance = (vertic_intersect(map, angle)).distance * cos(angle - map->angl);
            line_height = (TILESIZE / corrected_distance) * WIDTH;
        }
        //draw 3D
        begin = (HEIGHT / 2) - (line_height / 2);
        end = (HEIGHT / 2) + (line_height / 2);
        if (begin < 0)
            begin = 0;
        if (end > HEIGHT)
            end = HEIGHT;
        while(begin < end)
        {
            mlx_put_pixel(map->img, i, begin, 0xFF0000FF);
            begin++;
        }
            // draw_ray(map, map->xp, map->yp, map->angl, (vertic_intersect(map,angle)).distance, 0x00FF00FF);
        angle += FOV / WIDTH;
        i++;
    }
}
void draw_map(void *param)
{
    int i;
    int j;
    t_map *map;

    i = 0;
    map = (t_map *)param;
    if(map->img)
        mlx_delete_image(map->mlx, map->img);
    map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(map->mlx, map->img, 0, 0);
    if(!map->img)
    {
		write_err("Error\nFailed to create image\n");
		exit(1);
	}
    while(i < size_array(map->map))
    {
        j = 0;
        while(j < ft_strlen(map->map[i]))
        {
            if(map->map[i][j] == '1')
                draw_square(map,j,i,0x000000FF);
            else if(map->map[i][j] != ' ')
                draw_square(map,j,i,0xFFFFFFFF);
            j++;
        }
        i++;
    }
    mlx_put_pixel(map->img, map->xp , map->yp , 0xFF0000FF);
    mlx_put_pixel(map->img, map->xp, map->yp , 0xFF0000FF);
    mlx_put_pixel(map->img, map->xp , map->yp, 0xFF0000FF);
    mlx_put_pixel(map->img, map->xp, map->yp, 0xFF0000FF);
    draw_all_rays(map);
}







