#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void copy(const char* name, char* file)
{
	//source: http://www.programmingsimplified.com/c-program-copy-file
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
 
  
 
   source = fopen(name, "w");
 
   if( source == NULL )
   {
      
      exit(EXIT_FAILURE);
   }
 
 
 
   target = fopen(file, "w");
   
   if( target == NULL )
   {
      fclose(source);
      
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
 
   
 
   fclose(source);
   fclose(target);
 
   
}