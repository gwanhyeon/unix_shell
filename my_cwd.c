#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{    // 현재 경로 구하기
    char buf[BUFSIZ];
    char host_name[256] = {0x00};
    char user_name[256] = {0x00};
    char line[256] = {0x00};
    int len = 256;
    char *cwd;

    cwd = getcwd(NULL,BUFSIZ);
    getlogin_r(user_name,len);
    gethostname(host_name,len);
    printf("%s \n", user_name);
    printf("%s \n",host_name);
    printf("%s \n",cwd);

}
