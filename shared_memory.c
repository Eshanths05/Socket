#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *str;

    shmid = shmget(1234, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    strcpy(str, "Hello Shared Memory");

    printf("Data in shared memory: %s\n", str);

    shmdt(str);

    return 0;
}
