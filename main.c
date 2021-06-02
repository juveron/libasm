#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __linux__
#define OPEN_MAX FOPEN_MAX
#endif
extern ssize_t ft_read(int, void *, size_t);
void		ft_main_read(void)
{
    printf("-------------------ft_read-------------------\n");
    char		buff[100];
    int         fd;
    ssize_t     ret;

	printf("ft_read : \n");   
    	fd = open("test.txt", O_RDONLY);
    	ret = ft_read(fd, buff, 10);
    	buff[ret] = '\0';
	printf("buff = %sret = %zd\n", buff, ret);
	close(fd);

	printf("read : \n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buff, 10);
	buff[ret] = '\0';
	printf("buff = %sret = %zd\n", buff, ret);
    	close(fd);
	printf("----------\n");
	printf("ft_read : \n");
    	fd = open("lol.txt", O_RDONLY);
    	ret = ft_read(fd, buff, 10);
 	printf("errno : %d\n", errno);
    	buff[ret] = '\0';
	printf("buff = %sret = %zd\n", buff, ret);
	close(fd);

	errno = 0;
	printf("read : \n");
	fd = open("lol.txt", O_RDONLY);
	ret = read(fd, buff, 10);
 	printf("errno : %d\n", errno);
	buff[ret] = '\0';
	printf("buff = %sret = %zd\n", buff, ret);
    	close(fd);
	printf("----------\n");
	char	buf_read[2048];
	int tmp[2];

	printf("ft_read : \n");
    	ret = ft_read(-1, buf_read, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
	close(fd);
	errno = 0;
	printf("read : \n");
	ret = read(-1, buf_read, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
	printf("----------\n");
	printf("ft_read : \n");
    	ret = ft_read(tmp[0], NULL, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
	close(fd);
	errno = 0;
	printf("read : \n");
	ret = read(tmp[0], NULL, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
	printf("----------\n");
	printf("ft_read : \n");
    	ret = ft_read(OPEN_MAX + 1, buf_read, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
	close(fd);
	errno = 0;
	printf("read : \n");
	ret = read(OPEN_MAX + 1, buf_read, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %zd\n", buf_read, ret);
}

int     main()
{
	ft_main_read();
}
