#include <stdio.h>      // ¿¿¿¿¿ ¿¿¿¿¿
#include <stdlib.h>     // ¿¿¿ ¿¿¿¿¿
#include <unistd.h>     // ¿¿¿¿ ¿¿¿¿¿
#include <errno.h>      // ¿¿¿¿ ¿¿¿¿¿
#include <string.h>     // string ¿¿¿ ¿¿¿¿¿
int main(int argc,char *argv[])
{
	char* pathname;
//3 arguments in command line	
	if(argc==3){
		// //check if file to be moved exists
		if((access(argv[1],F_OK|W_OK))==0){
			// append name of the file to the given path name
			pathname = strcat(argv[2], argv[1]);
			// if link is succesfully created
			if(link(argv[1],argv[2])==0){
				// if file argv[1] is deleted from its original location
				if((unlink(argv[1]))==0){
					printf("%s succesfully moved to %s\n",argv[1],argv[2]);
				}
                // Link Deletion error
				else{
					
					perror("Link deletion error");
				}
			}
			// Link creation error
			else{
				perror("Link creation error");
			}
		}
		// File Error
		else{
			perror("File error");
		}
	}
	// invalid number ofargument
	else{
		printf("Invalid number of arguments : <command> <filename> <pathname/>\n");
	}


}

