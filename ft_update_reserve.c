/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:12:18 by cleiron           #+#    #+#             */
/*   Updated: 2026/10/29 18:37:22 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_reserve(char *reserve)
{
	char	*new_line;

	if(!reserve)
		return (NULL);
	new_line = ft_strchr(reserve, '\n');
	if (!new_line)
	{
		free(reserve);
		return NULL;
	}
	new_line = ft_strdup(new_line +1);
	free(reserve);
	return (new_line);
}