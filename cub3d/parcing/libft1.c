/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:12:30 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/14 11:25:12 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_atoi(const char *str, int max)
{
	int		i;
	int		sg;
	long	nb;

	sg = 0;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			sg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > max)
			return(-1);
		i++;
	}
	if (sg == 1)
		return (nb * -1);
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	while ((s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

static char	*is_null(char *s1, char *set)
{
	if (!set)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	i;
	int	j;
	int	t;
	char	*p;

	if (!s1 || !set)
		return (is_null(s1, set));
	i = 0;
	j = ft_strlen(s1);
	t = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < j && ft_strchr(set, s1[j - 1]))
		j--;
	p = (char *)malloc(sizeof(char) * j - i + 1);
	if (!p)
		return (NULL);
	while (s1[i] && t < j - i)
	{
		p[t] = s1[i + t];
		t++;
	}
	p[t] = '\0';
	return (p);
}