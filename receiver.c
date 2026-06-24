#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg
{
    long type;
    char text[100];
};

int main()
{
    int msgid;
    struct msg message;

    msgid = msgget(1234, 0666 | IPC_CREAT);

    msgrcv(msgid, &message, sizeof(message.text), 1, 0);

    printf("Received: %s\n", message.text);

    return 0;
}
