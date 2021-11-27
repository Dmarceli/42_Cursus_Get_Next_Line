# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int main()
{
	int fd;
	int line;

    char    *buf[1000];
	fd = open("big_line_no_nl", O_RDONLY);
	line = read(fd, buf, 1000);
	printf("%d\n\n" , line);
    line = read(fd, buf, 1000);
	printf("%d\n\n" , line);
}