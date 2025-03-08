/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:29:21 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 21:15:55 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>// deleted

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define MAX_INT 2147483647
#define MIN_INT -2147483648
typedef struct RGB
{
    double R;
    double G;
    double B;
}t_RGB;

typedef struct coord
{
    double x;
    double y;
    double z;
}t_coord;

typedef struct vect3d
{
    double x;
    double y;
    double z;
}t_vect3d;

typedef struct A
{
    double ratio;
    t_RGB color;
}t_A;

typedef struct C
{
    t_coord viewpoint;
    t_vect3d orientation_vect;
    double Horizontal_field;
}t_C;

typedef struct L
{
    t_coord lightpoint;
    double ratio;
    // + RGB bonus part
}t_L;

typedef struct sp
{
    t_coord sphere_center;
    double diameter;
    t_RGB color;
}t_sp;

typedef struct pl
{
    t_coord point;
    t_vect3d normal_vect;
    t_RGB color;
}t_pl;

typedef struct cy
{
    t_coord cylinder_center;
    t_vect3d axis_vect;
    double diameter;
    double height;
    t_RGB color;
}t_cy;

typedef struct scene
{
    t_A *A;
    t_C *C;
    t_L *L;
    t_sp *sp;
    t_pl *pl;
    t_cy *cy;
    int nb_A;
    int nb_C;
    int nb_L;
    int nb_sp;
    int nb_pl;
    int nb_cy;
    int err;
}t_scene;

typedef void				(*t_shapes)(char **split, t_scene *scene);
size_t	ft_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int x);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
void A(char **split, t_scene *scene);
void C(char **split, t_scene *scene);
void L(char **split, t_scene *scene);
void sp(char **split, t_scene *scene);
void pl(char **split, t_scene *scene);
void cy(char **split, t_scene *scene);
char	**multi_split(char *s, char *separators);
int	ft_strcmp(char *s1, char *s2);
char	*new_word(const char *s, int *i, char c);
void	err(char *str);
double atod(char *str, double min, double max, t_scene *scene);
// void traite_RGB(char *str, char *er, t_scene *scene);
// void traite_point(char *str, char *er, t_scene *scene);
// void traite_vect(char *str, char *er, t_scene *scene);
void free_2(char **col);
#endif