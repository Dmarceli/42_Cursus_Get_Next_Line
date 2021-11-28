/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:35:10 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/28 19:08:51 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

unsigned int	ft_strlen(char *str);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strdup(char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*get_next_line(int fd);

# define OPEN_MAX 65535

#endif
