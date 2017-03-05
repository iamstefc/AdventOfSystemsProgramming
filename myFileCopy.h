#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copy(char* name)
{
	//source: http://www.programmingsimplified.com/c-program-copy-file
   char ch, target_file[20]="";
	char *gets(char *str);
   
   FILE *source, *target;

   source = fopen(name, "r");
   if( source == NULL )
   {
      exit(EXIT_FAILURE);
   }
 
   target = fopen("temp", "w");

   if( target == NULL )
   {
      fclose(source);
      exit(EXIT_FAILURE);
   }

   while( ( ch = fgetc(source) ) != EOF )
   {
	   fputc(ch, target);
   }
printf("File copied successfully.\n");

   fclose(source);
   fclose(target);
}