/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:41:46 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/25 17:49:34 by cleiron          ###   ########.fr       */
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
 

char *get_next_line(int fd)
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
		pre_line = malloc(sizeof(char) * buffer_size + 1);
		if(!pre_line)
			return (NULL);
		while (i < nb_octs)
		{
			pre_line[j] = buffer[i];
			i++; 
			j++;
		}
		j = 0;
		while (pre_line[j] != "\n")
		{
			line[k] = pre_line[j]
			k++;
		}
	}
	return (line);
	
}

