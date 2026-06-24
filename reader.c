#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[100];

    int fd = open("myfifo", O_RDONLY);

    read(fd, buf, sizeof(buf));

    printf("Message: %s\n", buf);

    close(fd);

    return 0;
}
