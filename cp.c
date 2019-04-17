
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd1,fd2;
    int r_size,w_size;
    char buf[100];
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR|O_CREAT|O_EXCL, 0664);
    
    r_size = read(fd1,buf,100);
    w_size = write(fd2,buf,r_size);
    while(r_size == 100)
    {
        r_size=read(fd1,buf,100);
        w_size=write(fd2,buf,r_size);
    }


    return 0;    
}

