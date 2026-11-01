/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:11:12 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/29 18:05:55 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*buffer reçoit les éléments lu par read, ensuite on met dans la reserve
Fichier
   ↓ read()
Buffer temporaire
   ↓ ft_join_buffer()
Réserve static

1. Lire des caractères avec read().
2. Les placer dans un buffer temporaire.
3. Ajouter un \0 après les caractères réellement lus.
4. Accumuler ces caractères dans la réserve.
5. Continuer jusqu'à trouver un \n ou atteindre la fin du fichier.*/

char	*ft_read(int fd, char *reserve, size_t count)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) BUFFER_SIZE +1);
	if (! buffer)
		return (NULL);
	while (reserve == NULL || ft_strchr(reserve, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(reserve);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		reserve = ft_join_buffer(reserve, buffer);
	}
	free(buffer);
	return (reserve);
}