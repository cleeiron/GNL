/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:17:54 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/29 18:03:36 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *reserve)
{
	char	*line;
	int		i;

	i = 0;
	while (reserve[i] != '\n' && reserve[i] != '\0')
		i++;
	if (reserve[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i +1);
	if (!line)
		return (NULL);
	strlcpy(line, reserve, i +1);
	return (line);
}
