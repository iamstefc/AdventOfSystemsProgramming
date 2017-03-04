#include<stdio.h>

	int copy_file(char *old_filename, char  *new_filename)
	{
		FILE  *ptr_old, *ptr_new;
		errno_t err = 0, err1 = 0;
		int  a;

		err = fopen_s(&ptr_old, old_filename, "rb");
		err1 = fopen_s(&ptr_new, new_filename, "wb");

		if(err != 0)
			return  -1;

		if(err1 != 0)
		{
			fclose(ptr_old);
			return  -1;
		}

		while(1)
		{
			a  =  fgetc(ptr_old);

			if(!feof(ptr_old))
				fputc(a, ptr_new);
			else
				break;
		}

		fclose(ptr_new);
		fclose(ptr_old);
		return  0;
	}

	int  main(void)
	{
		
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
		
		char  filename_src[101], filename_dest[101];

		printf("\nSource file: ");
		gets_s(filename_src, 100);

		printf("\nDestination filename: ");
		gets_s(filename_dest, 100);

		if(copy_file(filename_src, filename_dest) == 0)
			printf("Copy Successful\n");
		else
			fprintf(stderr, "Error during copy!");
	}