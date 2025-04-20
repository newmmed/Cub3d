/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:15 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/21 00:26:50 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h> // khaaaaaaaaaask thydiiiihaaaa


#define WIDTH 1500
#define HEIGHT 800
#define TILESIZE 32
#define FOV M_PI / 3

typedef struct map
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int F[3];
    int C[3];
    char **map;
    int xp;
    int yp;
    double angl;
    mlx_t *mlx;
    mlx_image_t	*img;
    mlx_texture_t* tex;

    double wall_height;

    mlx_texture_t* tex_no;
    mlx_texture_t* tex_so;
    mlx_texture_t* tex_we;
    mlx_texture_t* tex_ea;
    // mlx_
}t_map;

typedef struct ray
{
    double distance;
    //angle
    int vert;
    int horiz;
    double pos_in_tile_x;
    double pos_in_tile_y;
    double wall_height;
}t_ray;


void write_err(char *str);
void input(char *str, t_map *map);
char	*get_next_line(int fd);
int	ft_strncmp(const char *s1, const char *s2, int n);
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int x);
int	ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
int	ft_strlcpy(char *dst, char *src, int size);
char	**multi_split(char *s, char *separators);
int	ft_atoi(const char *str, int max);
void	my_exit(char *str);
void	free2(char **s);
int	ft_strcmp(char *s1, char *s2);
int size_array(char **scene);
char	*ft_strtrim(char *s1, char *set);
void draw_map(void *map);



void key_hook(mlx_key_data_t keydata, void *param);
void normalize_angle(double *angle);


t_ray horiz_intersect(t_map *map, double angle);
t_ray vertic_intersect(t_map *map, double angle);
int	is_wall(t_map *map, double ax, double ay);

void draw_ray(t_map *map, double px, double py, double angle, double distance, int color);// a supp

void draw_tex(t_map *map, int x, double begin, t_ray ray);

#endif