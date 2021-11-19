/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:35:10 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/19 18:20:15 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>


unsigned int	ft_strlen(char const *str);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strdup(const char *s1);

char			*ft_substr(const char *s, unsigned int start, size_t len);

char			*get_next_line(int fd);

#endif
