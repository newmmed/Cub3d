/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:36:19 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/14 11:25:12 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int x)
{
	int	i;
	char	*str;
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((!s1 && !s2) || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1 && s1[(++i)])
		str[i] = s1[i];
	if (!s1)
		i = 0;
	while (s2[(i++) - len1])
		str[i - 1] = s2[i - len1 - 1];
	str[i - 1] = '\0';
	if (x == 1)
		free (s1);
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int	len;

	len = ft_strlen(s) + 1;
	dup = malloc(len * sizeof(*dup));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len);
	return (dup);
}