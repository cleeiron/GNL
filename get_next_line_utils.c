/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clpincho <clpincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:42:26 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/22 15:32:06 by clpincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, char c)
{
	char	*adress;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			adress = (char *)&s[i];
			return (adress);
		}
		i++;
	}
	if (s[i] == '\0')
		return ((char *)&s[i]);
	return (adress);
}

char	*ft_linecpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (&dest[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_total;
	char	*new;

	len_s1 = ft_strlen((char *)&s1);
	len_s2 = ft_strlen((char *)&s2);
	len_total = len_s1 + len_s2;
	new_char = malloc(sizeof(char *) len_total +1);
	if (!new_char)
		return (NULL);
	ft_linecpy(new_char, s1, len_s1);
	ft_linecpy(new_char, s2, len_s2);
	return (new_char);
}