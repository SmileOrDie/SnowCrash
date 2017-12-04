#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void print(char c)
{
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	int i;
	char buf[256];

	i = 0;
	fd = open (argv[1], O_RDONLY);
	ret = read(fd, buf, 256);
	buf[ret] = '\0';
	while (i < ret)
	{
		print(buf[i] - i);
		i++;
	}
	print('\n');
	return 0;
}
