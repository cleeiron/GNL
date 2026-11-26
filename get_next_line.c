/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clpincho <clpincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:41:46 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/26 16:04:46 by clpincho         ###   ########.fr       */
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


char *get_next_line(int fd)
{
	size_t nb_octs;
	char *buffer;
	size_t buffer_size;
	static char *pre_line;
	char *line;

	nb_octs = 0;
	//check buffersize
	//return null quand cest lq fin ud fichier
	// leak
	//valgrind --leak-check=full nm du prog
	//
	//while(read(fd, buffer, buffer_size) != 0)
	{
		nb_octs = read(fd, buffer, BUFFER_SIZE-1);
		while(i <nb_octs)
		{
			pre_line = ft_strjoin(buffer, preline);
			line = get_line(pre_line);
		}
	}
	return (line);

}

char	*get_line(char *s1)
{
	char 	*line;
	char	*temp;
	size_t	len;

	temp = ft_strchr(s1, '\n');
	len = (temp - s1);
	line = malloc(sizeof(char *) + len + 2);
	if (!line)
		return (NULL);
	if (*temp == '\n')
	{
		ft_linecpy(line, s1, len +1);
		line[len + 1] = '\0';
	}
	else
	{
		ft_linecpy(line, s1, len);
		line[len] = '\0';
	}
	return (line);
}


int main()
{
	char	*s1 = "hello\nsql";
	char	*s2 = "salut";
	char	*new;
	char	*line;

	new = ft_strjoin(s1, s2);
	printf("%s\n", new);
	line = get_line(s1);
	printf("%s\n", line);
	s1 = get_next_line(1);
	return (0);
}

