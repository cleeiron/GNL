/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clpincho <clpincho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:42:31 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/26 15:56:29 by clpincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//creer macro buffer size

char *get_next_line(int fd);
size_t	ft_strlen(char *s1);
char	*ft_strchr(const char *s, char c);
char	*ft_linecpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_line(char *s1);

#endif
