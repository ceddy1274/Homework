#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
        char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	fgets(write_msg, BUFFER_SIZE, stdin);

	pid_t pid;
	int p1[2];
        int p2[2];

	/* create the pipe */
	if (pipe(p1) == -1 || pipe(p2) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork Failed");
		return 1;
	}

	if (pid > 0) {  /* parent process */
		/* close the unused end of the pipe */
		close(p1[READ_END]);

		/* write to the pipe */
		write(p1[WRITE_END], write_msg, strlen(write_msg)+1); 

		/* close the write end of the pipe */
		close(p1[WRITE_END]);
		
		/* close unused end of the pipe */
		close(p2[WRITE_END]);
		
		/* read from the pipe */
		read(p2[READ_END], read_msg, BUFFER_SIZE);
		
		/* print message */
		printf("message from parent after child reverse %s\n",read_msg);
	
		/* close read end of the pipe */
		close(p2[READ_END]);
	}
	else { /* child process */
		/* close the unused end of the pipe */
		close(p1[WRITE_END]);

		/* read from the pipe */
		read(p1[READ_END], read_msg, BUFFER_SIZE);
                for(int i = 0; i < strlen(read_msg); i++)
                {
                    if (islower(read_msg[i]))
        	    {
            		read_msg[i] = toupper(read_msg[i]);
        	    }
        	    else if (isupper(read_msg[i]))
        	    {
            		read_msg[i] = tolower(read_msg[i]);
        	    }
                }
                //printf("child read %s\n",read_msg);
		/* close the read end of the pipe */
		close(p1[READ_END]);
		
		/* close the unused end of the pipe */
                close(p2[READ_END]);
		
		/* write to the pipe */
		write(p2[WRITE_END], read_msg, strlen(read_msg) + 1);

		/* close the write end of the pipe */
                close(p2[WRITE_END]);

	}

	return 0;
}
