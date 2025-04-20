/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:14:43 by hanebaro          #+#    #+#             */
/*   Updated: 2025/04/09 10:17:15 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free2(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return ;
}

void	my_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}