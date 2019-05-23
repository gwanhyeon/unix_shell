#include <stdio.h>		// 표준 입출력 라이브러리
#include <stdlib.h>		// 문자열 변환 라이브러리
#include <unistd.h>		// 접근권한 라이브러리
#include <fcntl.h>		// 파일제어 라이브러리
#include <sys/stat.h>   // 시스템 파일들의 정보 라이브러리
#include <errno.h>		// 에러처리 라이브러리
#define MAX 1000
char* buf[MAX];		// 버퍼값 지정

int main(int argc,char *argv[])
{
    struct stat statBuf;
    int file1, file2;
    // 인자 값이 제대로 들어왔을 경우
    if(argc==3){
        file1=open(argv[1],O_RDONLY);
        // 파일 오픈 체크
        if(file1==-1){
            perror("File creation error");
        }
        // 파일 생성
        else{
            // 생성시 파일 접근 권한(User/Group/Others)
            file2=open(argv[2],O_WRONLY|O_CREAT,0777);
            // 파일 생성 되었을 경우
            if(file2!=-1){
                
                // file1에서 MAX의 길이만큼 buf에 읽어 들인다.
                if(read(file1,buf,MAX)!=-1){
                    // file1에서 MAX의 길이만큼 buf에 쓴다.
                    if(write(file2,buf,MAX)!=-1){
                        printf("%s copied to %s\n",argv[1],argv[2]);
                    }
                }
                // 파일 읽기/쓰기 에러
                else{
                    if(!unlink(argv[2])){
                        printf("File had read/write errors");
                    }
                }
            }
        }
        fstat(file1,&statBuf);        // file1 파일의 상태 및 정보를 얻음
        fchmod(file2,statBuf.st_mode); // file1에 있는 st_mode를 사용하여 접근권한을 얻어서 적용시킴
        
        
    }
    // 인자 값 제대로 들어오지 않았을 경우
    else{
        printf("Error: Enter command followed by file to be copied and destination file\n");
    }
}

