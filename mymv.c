#include <stdio.h>      // 입출력 라이브러리
#include <stdlib.h>     // 문자열 라이브러리
#include <unistd.h>     // 접근권한 라이브러리
#include <errno.h>      // 에러처리 라이브러리
#include <string.h>     // 문자열 라이브러리
int main(int argc,char *argv[])
{
	char* pathname;
	// 명령어 인자 체크(성공)	
	if(argc==3){
		//파일 접근 체크
		if((access(argv[1],F_OK|W_OK))==0){
			
			// 경로가 포함되어 있는 경우 파일 이동
			if((strstr(argv[2],"/") || strstr(argv[2],"..") || strstr(argv[2],"../"))){
				pathname = strcat(argv[2], argv[1]);
				// 파일 이동 성공 확인
				if(link(argv[1],argv[2])==0){
					// 파일 unlink 처리
					if((unlink(argv[1]))==0){

						//printf("%s succesfully moved to %s\n",argv[1],argv[2]);
					}
					//파일 unlink 에러처리
					else{

						perror("Link deletion error");
					}
				}
				// 링크 생성 에러
				else{
					perror("Link creation error");
				}
			}else{
				//pathname = strcat(argv[2], argv[1]);
				// 파일 이동 성공 확인
				if(link(argv[1],argv[2])==0){
					// 파일 unlink 처리
					if((unlink(argv[1]))==0){
						//printf("%s succesfully rename to %s\n",argv[1],argv[2]);
					}
					//파일 unlink 에러처리
					else{

						perror("Link deletion error");
					}
				}
				// 링크 생성 에러
				else{
					perror("Link creation error");
				}



			}
		}
		// 파일 에러
		else{
			perror("File error");
		}
	}
	// 인자값 체크 실패
	else{
		printf("Invalid number of arguments : <command> <filename> <pathname/>\n");
	}


}
