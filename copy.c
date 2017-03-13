#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"
#include "printhelp.h"
#include "myFileCopy.h"
#include "sys/stat.h"
#include "errno.h"
#include "string.h"
#include "pwd.h"
#include "grp.h"


int main(int argc, char* argv[])
{  
  const char* name = argv[1];
	char* source = "~/Backup",* revision = "_rev";
  char*arg_d, *env_home,*backup, *current;
  char str[80]="";
	int opt = getopt(argc, argv, "mhd:t");
	bool opt_m =false, opt_d = false, opt_t =false, opt_h =false;
  int count = 0;
	
	
	

	if(argv[1] == NULL){
		printf("Usage: %s EXECUTABLE\n",argv[0]);	//part 2: if no arguments provided
		return 1;
	}
    
   
  struct stat file_stat;
  if (stat(name, &file_stat) < 0){ 
      printf("Error sourcing\n");					   //if source file does not exist
      return 1; 
  }
	
	
													                   //checks command line arguments
	while (opt != -1)
   {
      if (opt == 'm') {
         opt_m = true;
      } else if (opt == 'd') {
         opt_d = true;
         arg_d = optarg;
      } else if (opt == 't') {
         opt_t = true;
      } else if (opt == 'h') {
      	 opt_h = true;
      }
      opt = getopt(argc, argv, "mhd:t");
   }

   if(opt_h){printhelp(name); 							//prints out helpful info
   		return 0;}
   		


env_home = getenv("HOME");                  //gets home directory of any user
strcpy(str,env_home);                   
strcat(str,"/backup");                      
backup = str;
struct stat s;
int err = stat(source,&s);

if (opt_d){
	err = stat(backup,&s);
	}

if(-1 == err) {
if(ENOENT == errno){ 
	if(opt_d){ 
	backup = arg_d;}											    //directory does not exist
	mkdir(backup, S_IRWXG | S_IRWXO | S_IRWXU);
	printf("Backup Locations: %s\n",backup);
      
    } 
}
else{
	printf("Directory Already Exists\n");
}

char str2[1000] = "";

strcpy(str2,name); 
strcat(str2,revision);
char buffer[100] = "";    
sprintf(buffer,"%d", count);  

// SOURCE: http://stackoverflow.com/questions/5242524/converting-int-to-string-in-c
strcat(str2, buffer);
current = str2;
printf("BACKUP3 : %s\n", backup);
printf("current: %s\n", current);

char str3[1000] = "";
strcpy(str3,backup);
printf("%s\n", str3);                       //creating temp file in backup
strcat(str3,"/temp");
char* tempfile = str3;

 
printf("%s\n", current);
copy(name,current);
copy(name, tempfile);














/*stat(name, &file_stat);
struct group* gr = getgrgid(file_stat.st_gid);
struct passwd* pw = getpwuid(file_stat.st_uid);*/


















  
  




}
