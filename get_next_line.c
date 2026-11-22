/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clpincho <clpincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:41:46 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/22 17:01:34 by clpincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read() lit jusqu'à count octets depuis le descripteur de fichier fd dans le tampon pointé par buf.
//Si count vaut zéro, read() renvoie zéro et n'a pas d'autres effets. 
//Si count est supérieur à SSIZE_MAX, le résultat est indéfini.

//read() renvoie -1 s'il échoue, auquel cas errno contient le code d'erreur, 
//et la position de la tête de lecture est indéfinie. Sinon, read() renvoie le nombre d'octets lus 
//(0 en fin de fichier), et avance la tête de lecture de ce nombre. 
//Le fait que le nombre renvoyé soit plus petit que le nombre demandé n'est pas une erreur. 
//Ceci se produit à la fin du fichier, ou si on lit depuis un tube ou un terminal, 
//ou encore si read() a été interrompu par un signal. 

//Calculer la longueur des deux chaînes.
//Allouer suffisamment de mémoire pour les réunir.
//Copier les caractères de static, puis ceux de buffer.
//Ajouter le caractère \0 à la fin.
//Libérer l'ancienne allocation de static lorsqu'elle n'est plus nécessaire.
//Faire pointer static vers la nouvelle chaîne.
 

/*char *get_next_line(int fd)
{
	size_t i;
	size_t nb_octs;
	char *buffer;
	size_t buffer_size;
	static char *pre_line;
	char *line;
	size_t j;

	nb_octs = 0;
	while(read(fd, buffer, buffer_size) != 0)
	{
		i = 0;
		nb_octs = read(fd, buffer, buffer_size);
		
		line = ft
	return (line);

}*/

char	*get_line(char *s1)
{
	char 	*line;
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	temp = ft_strchr(s1, '\n');
	len = ((ft_strchr(s1, '\n')) - s1);
	while (i < len)
	{
		if (ft_strchr(s1, '\n'))
		{
			line = malloc(sizeof(char *) + len + 2);
			if (!line)
				return (NULL);
		}
		else
		{
			len = ft_strlen(s1);
			line = malloc(sizeof(char *) + len + 1);
			if (!line)
				return (NULL);
		}
			line[i] = s1[i];
			i++;
			line[i] = '\0';
	}
	
	return (line);
}

size_t	ft_strlen(char *s1)
{
	size_t	len;

	len = 0;
	while (s1[len] != '\0')
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

void	ft_linecpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_total;
	char	*new;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	len_total = len_s1 + len_s2;
	new = malloc(sizeof(char *) + len_total +1);
	if (!new)
		return (NULL);
	ft_linecpy(new, s1, len_s1);
	ft_linecpy(new + len_s1 -1, s2, len_s2);
	return (new);
}

int main()
{
	char	*s1 = "hello\nsql";
	char	*s2 = "salut";
	char	*new;
	char	*line;

	new = ft_strjoin(s1, s2);
	new = get_line(s1);
	free(s1);
	return (0);
}

