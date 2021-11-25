/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:06 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/25 22:28:22 by dmarceli         ###   ########.fr       */
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
	if (*saved == NULL)
		return (NULL);
	nlpos = pos_first_bl(*saved);
	if (nlpos == -1)
		return (*saved);
	linhaout = ft_substr(*saved, 0, nlpos + 1);
	if (nlpos + 1 != (int)ft_strlen(*saved))
	{
		temp = ft_substr(*saved, nlpos + 1, ft_strlen(*saved) - (nlpos + 1));
		if (*saved)
		{
			free(*saved);
			*saved = NULL;
		}
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
	char				buf[BUFFER_SIZE + 1];
	int					i;
	char				*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4096)
		return (NULL);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup("");
		buf[i] = '\0';
		temp = ft_strjoin(saved[fd], buf);
		//free(buf);
		if (*saved[fd])
		{
			free(saved[fd]);
			saved[fd] = NULL;
		}
		saved[fd] = ft_strdup(temp);
		if (temp)
			free (temp);
		if (pos_first_bl(saved[fd]) >= 0)
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	//printf("%p,%p,%p", saved, buf,temp);
	return (line_butcher(&saved[fd]));
}

int main()
{
	int fd;
	char *line;
	int i = 0;
	fd = open("big_line_no_nl", O_RDONLY);
	while (i < 10)
	{
	line = get_next_line (fd);
	printf("%s" , line);
	i++;
	}
}
