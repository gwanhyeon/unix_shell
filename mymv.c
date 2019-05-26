#include <stdio.h>		// 입출력 라이브러리1
#include <stdlib.h>		// 입출력 라이브러리2
#include <dirent.h>		// 디렉터리 라이브러리
#include <unistd.h>		// 접근권한 라이브러리
#include <string.h>		// 문자열 라이브러리
#define MAX 100
int main(int argv, char* argc[])
{
	char *file= argc[1];	 // 첫번째 파일 저장 변수
	char *mv_path= argc[2];	 // 두번째 파일 or 경로 변수
	char cur_path[100]; 	 // 현재 경로저장하기 위한 변수


	// 인자의 개수가 맞지 않을 경우 
	if(argv!=3){
		printf("Invalid number of arguments\n");
	}
	// 인자의 개수가 맞을 경우
	else
	{	
		// 파일 접근권한 체크
		if((access(file,F_OK|W_OK))==0){
			if(mv_path[0]=='/'){				//루트 패스 입력하였을 경우
				strcat(mv_path,"/");	
				strcat(mv_path,file);			// 루트 경로 설정
				// 파일, 경로 링크 생성(현재 경로에 rename )
				if(link(file,mv_path)==0){
					// 성공적으로 링크가 생성되었을 경우
					if((unlink(file) ==0)){
						//puts("file renamed!\n");
					}
				}
				// 디렉터리를 찾을 수 없을 경우
				else{
					printf("Error:\nDirectory not found\n");
				}
			}
			// 다른경로로 들어온경우 
			else{
				DIR *dir ;	// 디렉터리 변수선언
				dir = opendir(mv_path); 				// check if argument is a dir in cwd
				// 디렉터리 오픈에 문제가 생겼을 경우
				if(dir==NULL){	
					if(link(file,mv_path) != 0){
						printf("Error: file not moved\n");
					}else{
						if(unlink(file) ==0){
							//printf("successful\n");
						}
					}
				}
				// 디렉터리 오픈 성공한 경우(파일이동)
				else{
					char *pt;		
					pt = getcwd(cur_path, MAX);		// get current working directory path 
					strcat(cur_path,"/");				
					strcat(cur_path,mv_path);			// attach mv location to path ptrL
					strcat(cur_path,"/");
					strcat(cur_path, file);				// keep original file name
					//파일 이동 링크 생성
					if(link(file,pt)==0){
						// 이동후 링크 없애기
						if(unlink(file) == 0){
							//puts("file moved!\n");
						}
						else{
							printf("Error:\nDirectory not found in CWD\n");
						}
					}
					closedir(dir); // 디렉터리 종료
				}
			}
		}
	}
	return 0;
}
