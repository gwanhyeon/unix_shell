//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <string.h>
//#include <unistd.h>
//
//int main(int argc, char ** argv){
//	if (argc < 3){
//		fprintf(stderr, "minsh: Not enough arguments\n");
//		return 1;
//	}
//
//	// Try opening the last argument to see if it is a directory or a file
//	struct stat dirstat;
//	if (stat(argv[argc-1], &dirstat) < 0 || ! (S_ISDIR(dirstat.st_mode))){	
//		
//		// If the specified directory doesn't exist, it must be a file
//		// Or if it is a file that already exists, overwrite
//
//		if ( argc > 3 ){	// Only source file and destination file must be the arguments
//			fprintf(stderr, "minsh: Too many arguments\n");
//			return 1;
//		}
//		
//		// Copy source file into destination file
//		int fd_src, fd_dest;
//		char buffer[1024];
//		int nbytes;
//
//		fd_src = open(argv[1], O_RDONLY);
//
//		if ( fd_src < 0 ){
//			perror("minsh");
//			return 1;
//		}
//
//		fd_dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0755);
//		
//		if ( fd_dest < 0 ){
//			perror("minsh");
//			return 1;
//		}
//
//		nbytes = read(fd_src, buffer, 1024);
//		while (1){
//			if ( nbytes < 0 ){	// Error has occurred
//				perror("minsh");
//				close(fd_src);
//				close(fd_dest);
//				return 1;
//			}
//			else if ( nbytes == 0 ){	// End of file
//				break;
//			}
//			else{
//				write(fd_dest, buffer, nbytes);
//			}
//			nbytes = read(fd_src, buffer, 1024);
//		}
//		close(fd_src);
//		close(fd_dest);
//		
//		return 0;
//	}
//
//	// If execution reaches this point, a directory is the last argument, so open and write to the necessary files
//	int i = 1;
//	int fd_src, fd_dest;
//	char buffer[1024];
//	int nbytes;
//	char dest[1024];
//
//	for ( i = 1 ; i < argc - 1 ; i++ ){
//		fd_src = open(argv[i], O_RDONLY);
//
//		if (fd_src < 0){
//			perror("minsh");
//			return 1;
//		}
//		
//		// Find the path to the destination file
//		strcpy(dest, argv[argc-1]);
//		strcat(dest, "/");
//		strcat(dest, argv[i]);
//
//		fd_dest = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0755);
//		
//		if ( fd_dest < 0 ){
//			perror("minsh");
//			return 1;
//		}
//
//		nbytes = read(fd_src, buffer, 1024);
//		while (1){
//			if ( nbytes < 0 ){	// Error has occurred
//				perror("minsh");
//				close(fd_src);
//				close(fd_dest);
//				return 1;
//			}
//			else if ( nbytes == 0 ){	// End of file
//				break;
//			}
//			else{
//				write(fd_dest, buffer, nbytes);
//			}
//			nbytes = read(fd_src, buffer, 1024);
//		}
//		close(fd_src);
//		close(fd_dest);
//	}
//	return 0;
//}
//


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
    char *path;
    char *cwd;
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
	    path = getcwd(cwd, MAX);
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
			if(!mkdir(argv[2],0775)){
			// mkdir
			}	
               }
            }else{

		printf("파일 오픈 실패\n");
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

