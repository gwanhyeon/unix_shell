//  myShell.c/  유닉스 쉘 프로그래밍 Quiz - 2
//  List of Unix my Shell Function
//  $mv, cp, exit, clear
//  Created by kgh(Gwan Hyeon Kim) on 25/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
/*
 
this is Program How does it work?
$gcc -o "object $file name" myShell.c

* $clear
$clear
터미널의 명령행들 모두 clear
 
* $mv
$mv unix.c unix_exam.c
unix.c to unix_exam.c 파일명 변경
$mv unix.c ..
이전 디렉터리로 unix.c 값 이동
 
* $cp
$cp unix.c unix_exam.c
unix_c to unix_exam.c 복사
 
* $exit
$exit
System exit(0)
*/

#include <stdio.h>      // 입출력 라이브러리
#include <stdlib.h>     // 표준 문자열,메모리 라이브러리
#include <string.h>     // 표준 문자열 라이브러리
#include <unistd.h>     // 다양한 상수와 자료형 함수 관련 라이브러리
#include <fcntl.h>      // 파일 입출력 관련 라이브러리
#include <sys/stat.h>   // 시스템 파일들의 정보 라이브러리
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>


#define MAX 100        // 초기값 설정
char* buf[MAX];         // 저장공간 buf 초기값 MAX
// Function 1. 유닉스 mv 명령어
void mymv(int argc,char *argv[])
{
    char* pathname;
    // command arguments
    if(argc==3){
        // 이동시킬 파일이 있는지 확인(읽기 / 쓰기 여부)
        if((access(argv[1],F_OK|W_OK))==0){
            // 지정된 경로 이름에 파일의 이름을 추가
            pathname = strcat(argv[2], argv[1]);
            // 링크 성공적으로 생성된 경우
            if(link(argv[1],argv[2])==0){
                // argv [1] 파일이 원래 위치에서 성공적으로 삭제 된 경우(링크 개수 감소, 디렉토리 항목 삭제)
                if((unlink(argv[1]))==0){
                    printf("%s succesfully moved to %s\n",argv[1],argv[2]);
                }
               else{
                    // argv [1] 파일이 원래 위치에서 링크가 삭제되지 않은경우 에러 표시
                    perror("Link deletion error");
                }
            }
            // 링크 생성 실패한 경우
            else{
                perror("Link creation error");
            }
        }
        // argv[1] 파일이 존재하지 않을 경우 에러 표시
        else{
            perror("File error");
        }
    }
    // arguments 수가 올바르지 않을 경우
    else{
        printf("Invalid number of arguments : <command> <filename> <pathname/>\n");
    }
    
    
}
// Function 2. 유닉스 cp 명령어

void mycp(int argc,char *argv[])
{
    int fd1, fd2;
    // 인자의 수가 유효한 경우
    if(argc==3){
        fd1=open(argv[1],O_RDONLY);
        // 파일이 열려 있는 경우
        if(fd1==-1){
            perror("File creation error");
        }
        // 파일이 열려 있지 않고 성공적인 경우
        else{
            fd2=open(argv[2],O_WRONLY|O_CREAT,0777);
            // 파일이 성공적으로 오픈 되었으면 파일 생성
            if(fd2!=-1){
                //파일 읽기
                if(read(fd1,buf,MAX)!=-1){
                    // 파일 쓰기
                    if(write(fd2,buf,MAX)!=-1){
                        printf("File %s copied to %s\n",argv[1],argv[2]);
                    }
                }
                //파일에 읽기 / 쓰기 오류, 생성 된 인자 두 번째 파일을 삭제
                else{
                    if(!unlink(argv[2])){
                        printf("File had read/write errors; hence delete the 2nd file created");
                    }
                }
            }
        }
    }
    // 인자의 수가 잘못된 경우
    else{
        printf("Error: Enter command followed by file to be copied and destination file\n");
    }
}
char* my_getcwd(char* user_name)
{
   char* cwd;
   char* home_path;
   int str_len;
   home_path = (char *)malloc(strlen(user_name) + strlen("/home/")) + 1;
   home_path[strlen(user_name) + strlen("/home/")] = '\0';
   sprintf(home_path, "/home/%s", user_name);
   cwd = getcwd(NULL, MAX);

       if(strstr(cwd, home_path) == NULL){
				
               return cwd;
	   }
		   
	   else{
               str_len = strlen(home_path);
		//	   puts(str_len);
               cwd[str_len-1] = '~';
               return &cwd[str_len-1];
       }
}
int mypwd(){
	char buffer[100];
	if(getcwd(buffer,sizeof(buffer))){
		printf("%s\n",buffer);
	}else{
		perror("getcwd");
	}
	return 0;

}

int mycd(int argc, char *argv[])
{
	char cwd[100];

	if(argc!=2) //If the path of the directory is not specified, display a error message.
	{
		if(!chdir("/")){
			//puts(cwd);
			if(getcwd(cwd,sizeof(cwd)) != NULL){
					puts(cwd);
			}
		}


		//}

		//}
		//printf("Invalid number of arguments\n");
		return 0; 
	}
//	if(!strcmp(argv[0], "\0")){
//		puts(cwd);
//	}
		if(!chdir(argv[1])) //chdir successful, if zero is returned.
	{
		//puts(cwd);
		//printf("Current working directory changed to ");
		if(getcwd(cwd,sizeof(cwd)) != NULL) // Stores the Current working directory in cwd if NULL is not returned.
		{
			puts(cwd);  //Display the current working directory.
		}
		else
		{
			perror("getcwd"); //Display the error occurred with getcwd.
		}
	}
	else
	{
		perror("chdir");  //Display the occur that occurred while trying to change the current working directory.
	}

	return 0;
}
void setHistroy(){


}

void getHistroy(){


}
void myEcho(char ** args){
	int i = 1;
	while (1){
		// End of arguments
		if (args[i] == NULL){
			break;
		}
		printf("%s ", args[i]);
		i++;
	}
	printf("\n");
}

int main()
{

	char getCommand[MAX];       // 명령을 담기위한 변수
    char *tokens[MAX];  // 문자열 토큰을 담기위한 변수
    int cnt;    // 문자 개수 처리(counting variable)
    char *cwd;  // 현재 경로를 받아내기 위한 변수 path
    char host_name[MAX];       // host_name kgh~local
    char user_name[MAX];        // user_name kgh
    int len = MAX;
	
    getlogin_r(user_name,len);
    gethostname(host_name,len);
// tokenizer
	while(1){ // 명령어를 계속 받기위한 loop
		cnt=0;
		
		// 실제 리눅스 명령어 처럼 처리 (host_name/local path)$
		//printf("%s:%s$ ",host_name,cwd);
		cwd = my_getcwd(user_name);
		fprintf(stdout,"%s@%s:%s$",user_name,host_name,cwd);
		// 줄바꿈 문자 제거
		fgets(getCommand,sizeof(getCommand)-1,stdin);
		//gets(getCommand);
		getCommand[strlen(getCommand)-1] = '\0';
		//fgets(getCommand,sizeof(getCommand)-1,stdin);
		tokens[cnt++]=strtok(getCommand," "); // argv[1] 인자 추출 하기 위함(Command)
		// " " 일경우 처리 해주기(Enter)
		if(tokens[0] != '\0'){
			while((tokens[cnt++] = strtok(NULL," "))); //모든 인수를 명령에 추출하여 토큰에 저장
			// fgets 함수는 \n를 포함하므로 \n strtok
			if(!strcmp(tokens[0],"exit")){ // $exit 명령으로 인자가 들어온 경우
				exit(0); // 해당 myShell 프로그램 시스템 종료
			}
			else if(!strcmp(tokens[0],"cp")){ //$cp(copy) 명령으로 인자가 들어온 경우
				mycp(cnt-1,tokens); // $mycp command 함수 호출
			}
			else if(!strcmp(tokens[0],"mv")){// $mymv 명령으로 인자가 들어온 경우
				mymv(cnt-1,tokens); // $mymv command 함수 호출
			}else if(!strcmp(tokens[0],"history")){

			}else if(!strcmp(tokens[0],"pwd")){
				mypwd();
			}else if(!strcmp(tokens[0],"cd")){
				mycd(cnt-1,tokens);			
			}else if(!strcmp(tokens[0],"echo")){
				myEcho(tokens);
			}
			else if(!strcmp(tokens[0], "clear")) //$clear 명령으로 인자가 들어온 경우
			{
				system("clear");
			}
		}
		
		



	}
	return 0;
}

