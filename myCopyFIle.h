#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[])
{
	// source: http://www.cprogramming.com/tutorial/c/lesson14.html
	if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else 
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int x;
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
	}
	
	// http://stackoverflow.com/q/36208198
  int b=1;
  char backup[100];
  char *source=getenv("BackupSource");
  char *destination=getenv("BackupDestination");
  char *btime=getenv("BackupTime");

  time_t getTime;
  struct tm *actualTime;
  time(&getTime);
  actualTime=localtime(&getTime);
  strftime(backup, 100, "%H:%M", actualTime);

   while(b)
    {
       while(strcmp(backup,btime)!=0)
         {
           sleep(60);
         }
       system("cp -r $BackupSource $BackupDestination");
    }

return 0;
}

		
		char  filename_src[101], filename_dest[101];

		printf("\nSource file: ");
		gets_s(filename_src, 100);

		printf("\nDestination filename: ");
		gets_s(filename_dest, 100);

		if(copy_file(filename_src, filename_dest) == 0)
			printf("Copy Successful\n");
		else
			printf(stderr, "Error during copy!");
	}