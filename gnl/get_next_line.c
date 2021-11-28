#include "get_next_line.h"

int nlpos(char *s)
{
	int		i;
	int		position;

	position = -1;
	i = 0;
	while (i <= (int)ft_strlen(s))
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

char *ft_processor(char **saved)
{
    char *out;
    char *data;
    int nl;

    if (!*saved || **saved == '\0')
		return (0);
    nl = nlpos(*saved);
    if (nl > -1)
    {
        out = ft_substr(*saved, 0 , nl + 1);
        data = ft_substr(*saved , nl + 1, ft_strlen(*saved));
        free (*saved);
        *saved = data;
        if (**saved != '\0')
		    return (out);
    }
    else
        out = ft_strdup(*saved);
    free (*saved);
    *saved = NULL;
    return(out);
}

char *get_next_line(int fd)
{
    static char *saved[OPEN_MAX];
    char        buf[BUFFER_SIZE + 1];
    int         read_bytes;
    char        *concat;

    concat = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (0);
    // buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!buf)
	// 	return (NULL);
    read_bytes = read(fd, buf, BUFFER_SIZE);
    while (read_bytes > 0)
    {
        buf[read_bytes] = '\0';
        if (saved[fd] == NULL)
            saved[fd] = ft_strdup("");
        concat = ft_strjoin(saved[fd], buf);
        free (saved[fd]);
        saved[fd] = concat;
        if (nlpos(saved[fd]) >= 0)
            break;
        read_bytes = read(fd, buf, BUFFER_SIZE);
    }
    //free (buf);
    return(ft_processor(&saved[fd]));
}

int main()
{
	int fd;
	char *line;
	int i = 0;
	fd = open("big_line_no_nl", O_RDONLY);
	while (i < 1)
	{
	line = get_next_line (fd);
	printf("%s" , line);
	i++;
	}
}