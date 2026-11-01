/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:42:51 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/29 17:37:01 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Calculer la taille nécessaire.
Allouer une nouvelle zone mémoire.
Copier les caractères de l'ancienne réserve.
Ajouter les caractères du buffer.
Libérer l'ancienne réserve.
Retourner la nouvelle réserve.
nous prenons de buffer pour mettre dans reserve*/

char	*ft_join_buffer(char *reserve, char *buffer)
{
	char	*new_reserve;
	size_t	lentotal;

	if (!reserve)
	{
		reserve = ft_strdup("");
		if (!reserve)
			return (NULL);
	}
	lentotal = ft_strlen(reserve) + ft_strlen(buffer) +1;
	new_reserve = malloc(sizeof(char) * lentotal);
	if (!new_reserve)
	{
		free(reserve);
		return (NULL);
	}
	ft_strlcpy(new_reserve, reserve, lentotal);
	ft_strlcat(new_reserve, buffer, lentotal);
	free(reserve);
	return (new_reserve);
}