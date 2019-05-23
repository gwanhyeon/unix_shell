#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
    time_t curr;
    struct tm *d;
    curr=time(NULL);
    d=localtime(&curr);
    printf("%s", asctime(d));
    return 0;
}


