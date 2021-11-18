/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:35:10 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/13 22:23:32 by dmarceli         ###   ########.fr       */
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

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

char			*ft_substr(const char *s, unsigned int start, size_t len);

#endif
