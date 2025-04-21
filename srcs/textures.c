/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:25:37 by mjadid            #+#    #+#             */
/*   Updated: 2025/04/22 00:20:23 by mjadid           ###   ########.fr       */
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

void	texture_to_image(t_map *m, double img_x, double img_y, double wall_x)
{
	uint8_t			*pixelx;
	uint8_t			*pixeli;
	t_texture		t;

	t.wall_y = 1;
	if (m->wall_height > HEIGHT)
		t.wall_y = ((HEIGHT - m->wall_height) / 2);
	t.tex_pos_x = (float) wall_x * (m->tex->width / TILESIZE);
	t.i = 0;
	while (t.i < m->wall_height && t.i < HEIGHT)
	{
		t.tex_pos_y = (float)(t.i - t.wall_y) 
			*(m->tex->height / m->wall_height);
		if ((((int) t.tex_pos_y * m->tex->width) 
				+ (int) t.tex_pos_x) < (m->tex->width * m->tex->height))
		{
			pixelx = &m->tex->pixels[((((int) t.tex_pos_y) * 
						m->tex->width) + ((int) t.tex_pos_x))
				* m->tex->bytes_per_pixel];
			pixeli = &m->img->pixels[(int)((int)(img_y + t.i)
					*m->img->width + (int)(img_x)) *m->tex->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, m->tex->bytes_per_pixel);
		}
		t.i++;
	}
}

void	draw_tex(t_map *map, int x, double begin, t_ray ray)
{
	double	wall_x;

	wall_x = ray.pos_in_tile_y;
	map->tex = map->tex_no;
	if (ray.pos_in_tile_x == 0)
	{
		map->tex = map->tex_so;
		wall_x = ray.pos_in_tile_y;
	}
	if (ray.pos_in_tile_x >= TILESIZE - 0.0001)
	{
		map->tex = map->tex_no;
		wall_x = ray.pos_in_tile_y;
	}
	if (ray.pos_in_tile_y == 0)
	{
		map->tex = map->tex_ea;
		wall_x = ray.pos_in_tile_x;
	}
	if (ray.pos_in_tile_y >= TILESIZE - 0.0001)
	{
		map->tex = map->tex_we;
		wall_x = ray.pos_in_tile_x;
	}
	texture_to_image(map, x, begin, wall_x);
}
