#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    message.type = 1;
    strcpy(message.text, "Hello Queue");

    msgsnd(msgid, &message, sizeof(message.text), 0);

    printf("Message Sent\n");

    return 0;
}
