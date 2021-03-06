/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:42:10 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/30 14:42:16 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

unsigned int	ft_strlen(char *str);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strdup(char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*get_next_line(int fd);

# define OPEN_MAX 100000

#endif