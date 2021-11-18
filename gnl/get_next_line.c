/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:06 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/18 17:04:45 by dmarceli         ###   ########.fr       */
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
		else
			i++;
	}
	return (position);
}

char	*line_butcher(char **saved)
{
	int		nlpos;
	char	*temp;
	char	*linhaout;

	nlpos = pos_first_bl(*saved);
	if (nlpos >= 0)
	{
		linhaout = ft_substr(*saved, 0, nlpos + 1);
		temp = ft_substr(*saved, nlpos + 1, ft_strlen(*saved));
		free(*saved);
		*saved = temp;
		return (linhaout);
	}
	return (*saved);
}

char	*get_next_line(int fd)
{
	char				*linhaout;
	static char			*saved;
	char				*buf;
	int					i;
	char				*temp;

	i = 0;
	if ((read(fd, 0, 0) == -1) || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (saved = NULL)
			saved = ft_strdup("");
		temp = ft_strjoin(saved, buf);
		free (saved);
		saved = temp;
		line_butcher(&saved);
		return (line_butcher(&saved));
	}
	return (linhaout);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*linha;

	linha = "";
	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while (linha)
	{
		linha = get_next_line(fd);
		if (linha)
			printf("%s\n", linha);
	}
}
