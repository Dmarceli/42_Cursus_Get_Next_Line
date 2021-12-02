/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:41:23 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/30 14:41:27 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	safe_free(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

int	nlpos(char *s)
{
	int		i;
	int		position;

	position = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{	
			position = i;
			break ;
		}
		i++;
	}
	return (position);
}

char	*ft_processor(char **saved)
{
	char	*out;
	char	*data;
	int		nl;

	if (!*saved || **saved == '\0')
		return (0);
	nl = nlpos(*saved);
	if (nl > -1)
	{
		out = ft_substr(*saved, 0, nl + 1);
		data = ft_substr(*saved, nl + 1, ft_strlen(*saved));
		safe_free (&*saved);
		*saved = data;
		if (**saved != '\0')
			return (out);
	}
	else
		out = ft_strdup(*saved);
	safe_free (&*saved);
	*saved = NULL;
	return (out);
}

char	*get_next_line(int fd)
{
	static char		*saved[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*concat;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buf[read_bytes] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup("");
		concat = ft_strjoin(saved[fd], buf);
		safe_free (&saved[fd]);
		saved[fd] = concat;
		if (nlpos(saved[fd]) >= 0)
			break ;
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_processor(&saved[fd]));
}
