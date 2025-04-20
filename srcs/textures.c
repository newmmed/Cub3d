/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:25:37 by mjadid            #+#    #+#             */
/*   Updated: 2025/04/21 00:30:40 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../includes/cub3d.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = -1;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !src)
		return (0);
	while (++i < n)
		s1[i] = s2[i];
	return (dst);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (dst > src)
	{
		while (len != 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	else
		ft_memcpy(s1, s2, len);
	return (dst);
}

void	texture_to_image(t_map *map, double img_pos_x, double img_pos_y, double wall_x)
{
	mlx_texture_t	*tex;
	uint8_t			*pixelx;
	uint8_t			*pixeli;
	double		tex_pos_x;
	double		tex_pos_y;
	int				i;
    double wall_y;

	tex = map->tex;
	wall_y = 1;
	if (map->wall_height > HEIGHT)
		wall_y = ((HEIGHT - map->wall_height) / 2);
	tex_pos_x = (float) wall_x * (tex->width / TILESIZE);
	i = 0;
	while (i < map->wall_height && i < HEIGHT)
	{
		tex_pos_y = (float)(i - wall_y) *(tex->height / map->wall_height);
		if ((((int) tex_pos_y * tex->width) + (int) tex_pos_x) < (tex->width * tex->height))
		{
			pixelx = &tex->pixels[((((int) tex_pos_y) * tex->width)
					+ ((int) tex_pos_x)) * tex->bytes_per_pixel];
			pixeli = &map->img->pixels[(int) ((int) (img_pos_y + i)
					* map->img->width + (int) (img_pos_x)) * tex->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, tex->bytes_per_pixel);
		}
		i++;
	}
}


void draw_tex(t_map *map, int x, double begin, t_ray ray)
{
    map->tex = map->tex_no;
    double wall_x = ray.pos_in_tile_y;
    if (ray.pos_in_tile_x == 0)
    {
        map->tex = map->tex_so;
        wall_x = ray.pos_in_tile_y;
    }
    if (ray.pos_in_tile_x >= TILESIZE - 0.1)
    {
        map->tex = map->tex_no;
        wall_x = ray.pos_in_tile_y;
    }
    if (ray.pos_in_tile_y == 0)
    {
        map->tex = map->tex_ea;
        wall_x = ray.pos_in_tile_x;
    }
    if (ray.pos_in_tile_y >= TILESIZE - 0.1)
    {
        map->tex = map->tex_we;
        wall_x = ray.pos_in_tile_x;
    }
    double img_pos_x = x;
    double img_pos_y = begin;
    texture_to_image(map, img_pos_x, img_pos_y, wall_x);
}
