/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:13:49 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/29 18:41:40 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;
	reserve = ft_read(fd, reserve, BUFFER_SIZE);
	if (!reserve)
		return (NULL);
	line = extract_line(reserve);
	reserve = ft_update_reserve(reserve);
	if (!line)
		return (NULL);
	return (line);
}
