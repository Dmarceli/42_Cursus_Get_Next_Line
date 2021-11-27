/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:06 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/26 18:47:37 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	pos_first_bl(char *s)
{
	int		i;
	int		comprimento;
	int		position;

	position = -1;
	i = 0;
	comprimento = ft_strlen(s);
	while (i <= comprimento)
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

char	*line_butcher(char **saved)
{
	int		nlpos;
	char	*temp;
	char	*linhaout;

	linhaout = NULL;
	temp = NULL;
	if (!*saved || **saved == '\0')
		return (NULL);
	nlpos = pos_first_bl(*saved);
	if (nlpos == -1)
		return (*saved);
	linhaout = ft_substr(*saved, 0, nlpos + 1);
	if (nlpos + 1 != (int)ft_strlen(*saved))
	{
		temp = ft_substr(*saved, nlpos + 1, ft_strlen(*saved) - (nlpos + 1));
		free(*saved);
		*saved = temp;
	}
	else
	{
		if (*saved)
		{	
			free (*saved);
			*saved = NULL;
		}
	}
	return (linhaout);
}

char	*get_next_line(int fd)
{
	static char			*saved[4096];
	char				*buf;
	int					i;
	char				*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4096)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// if (i == 0)
	// 	return(NULL);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup("");
		temp = ft_strjoin(saved[fd], buf);
		free(saved[fd]);
		saved[fd] = temp;
		if ((pos_first_bl(saved[fd]) >= 0))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
		//printf("%d\n" , i);
	}
	free (buf);
	return (line_butcher(&saved[fd]));
}

int main()
{
	int fd;
	char *line;
	int i = 0;
	fd = open("big_line_no_nl", O_RDONLY);
	while (i < 90)
	{
	line = get_next_line (fd);
	printf("%s" , line);
	i++;
	}
}
