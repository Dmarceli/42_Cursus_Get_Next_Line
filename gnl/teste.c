/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:53:13 by dmarceli          #+#    #+#             */
/*   Updated: 2021/11/18 15:35:11 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

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
		temp = ft_substr(*saved, nlpos + 1, ft_strlen(*saved) + 1);
		free(*saved);
		*saved = temp;
		return (linhaout);
	}
	return (*saved);
}

int main()
{
	char *saved;
	char *teste;

	saved = (char *)malloc(20);
	for (int i = 0; i < 10; i++)
		saved[i] = 'a';
	saved[10] = '\n';
	saved[11] = 'b';
	saved[12] = 'b';
	saved[13] = '\0';
	printf("%s", line_butcher(&saved));
	return (0);
}