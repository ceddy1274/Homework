/*Use ordinary pipes to create a filecopy system. Program will be passed two parameters: file name to be copied, file name of the copied version. 
  Write the contents of the copied file to a pipe, and have the child process copy it into the file to be copied. */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 255
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
	const char* orginalFile = argv[1];
	const char* copyFile = argv[2];
	
        char* writeChar;
        char read_msg[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];
        pid_t pid;
        int p1[2];
       

        /* create the pipe */
        if (pipe(p1) == -1) {
                fprintf(stderr,"Pipe failed");
                return 1;
        }

        /* now fork a child process */
        pid = fork();

        if (pid < 0) {
                fprintf(stderr, "Fork failed");
                return 1;
        }

        if (pid > 0) {  /* parent process */
                /* close the unused end of the pipe */
                close(p1[READ_END]);
		
		/* read input file */
		FILE *src = fopen(orginalFile, "r");
		
		/* check to see if file exists */
		if(src == NULL)
		{
		   printf("Unable to open file\n");
		   return 1;
		}
		
		while(fgets(buffer, BUFFER_SIZE, src) != NULL)
		{
		   /* write to the pipe */
                   write(p1[WRITE_END], buffer, strlen(buffer));	
		}
		
		
		/* close the file */
		fclose(src);
 
                /* close the write end of the pipe */
                close(p1[WRITE_END]);
                
		
        }
        else { /* child process */
                /* close the unused end of the pipe */
                close(p1[WRITE_END]);
		
		/* create file object for write file */
		FILE *copy = fopen(copyFile, "w");
		if(!copy)
		{
		   printf("Can't create stream\n");
		   return 1;
		}
		
		/*ensure when writing to file it will be null terminated */
		memset(read_msg, 0, BUFFER_SIZE);
		
		// use to track number of bytes read so far */
		ssize_t bytes_read;

                /* read from the pipe */
                while((bytes_read = read(p1[READ_END], read_msg, BUFFER_SIZE - 1)) > 0)
		{
		   fputs(read_msg, copy);
		}
		
		/* close the file */
		fclose(copy);
	
                /* close the read end of the pipe */
                close(p1[READ_END]);
		

        }

        return 0;
}

