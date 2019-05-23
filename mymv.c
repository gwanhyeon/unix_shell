#include <stdio.h>      // ¿¿¿¿¿ ¿¿¿¿¿
#include <stdlib.h>     // ¿¿¿¿¿¿¿¿
#include <unistd.h>     // ¿¿¿¿ ¿¿¿¿¿
#include <errno.h>      // ¿¿¿¿ ¿¿¿¿¿
#include <string.h>     // string ¿¿¿ ¿¿¿¿¿
int main(int argc,char *argv[])
{
	char* pathname;
	// ¿¿¿ ¿¿ ¿¿
	if(argc==3){
		// ¿¿ ¿¿¿ ¿ ¿¿ ¿¿ ¿¿¿¿ ¿¿ 
		if((access(argv[1],F_OK|W_OK))==0){
			// ¿¿ path ¿ ¿¿
			pathname = strcat(argv[2], argv[1]);
			// ¿¿ ¿¿¿ ¿¿¿¿ ¿¿ 
			if(link(argv[1],argv[2])==0){
				// ¿¿ ¿¿ ¿¿¿¿ ¿¿ 
				if((unlink(argv[1]))==0){
					printf("%s succesfully moved to %s\n",argv[1],argv[2]);
				}
                // ¿¿ ¿¿ ¿¿
				else{
					
					perror("Link deletion error");
				}
			}
			// ¿¿ ¿¿ ¿¿
			else{
				perror("Link creation error");
			}
		}
		// ¿¿¿¿
		else{
			perror("File error");
		}
	}
	// ¿¿¿ ¿¿ ¿¿ 
	else{
		printf("Invalid number of arguments : <command> <filename> <pathname/>\n");
	}


}

