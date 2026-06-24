#include <stdio.h>
#include <pthread.h>

void *hello(void *arg)
{
    printf("Hello Thread\n");
    return NULL;
}

int main()
{
    pthread_t t;

    pthread_create(&t, NULL, hello, NULL);

    pthread_join(t, NULL);

    return 0;
}
