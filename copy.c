#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"
#include "printhelp.h"
#include "watch.h"
#include "myFileCopy.h"
#include "sys/stat.h"
#include "errno.h"
#include "string.h"
#include "pwd.h"
#include "grp.h"


int main(int argc, char* argv[])
{  
	char* source = "~/Backup";
	const char* name = argv[1];
	char* arg_d;
	int opt = getopt(argc, argv, "mhd:t");
	bool opt_m =false, opt_d = false, opt_t =false, opt_h =false;
	ssize_t EVENT_SIZE = (sizeof (struct inotify_event));
	ssize_t EVENT_BUF_LEN = (1024 * (EVENT_SIZE + 16));
	
	

	if(argv[1] == NULL){
		printf("Usage: %sEXECUTABLE\n",argv[0]);	//part 2: if no arguments provided
		return 1;
	}
    
   
   struct stat file_stat;
   if (stat(name, &file_stat) < 0){ 
        printf("Error sourcing\n");					//if source file does not exist
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
   		



	//backup();
  //watch(name);

char* home = getenv("HOME");
char str[80]="";
strcpy(str,home);
strcat(str,"/backup");
char* path = str;
struct stat s;
int err = stat(source,&s);

if (opt_d){
	err = stat(path,&s);
	}

if(-1 == err) {
if(ENOENT == errno){ 
	if(opt_d){ 
	path = arg_d;}											//directory does not exist
	mkdir(path, S_IRWXG | S_IRWXO | S_IRWXU);
	printf("Backup Locations: %s\n",path);
       
    } 
}
else{
	printf("Directory Already Exists\n");
}

char n_copy[100];
char* current = "_rev0";
int count = 0;

current = n_copy;


strcpy(str,path);
strcat(str,"/temp");
path = str;

char* temp = path;

copy(name,temp);









//INOTIFY ------------------------

/*int length, i = 0;
  int fd;
  int wd;
  char buffer[EVENT_BUF_LEN];

 
  fd = inotify_init();

  
  if ( fd < 0 ) {
    perror( "inotify_init" );
  }
wd = inotify_add_watch( fd, name, IN_MODIFY| IN_DELETE );

  /*read to determine the event change happens on “/tmp” directory. Actually this read blocks until the change event occurs*/ 

  /*length = read( fd, buffer, EVENT_BUF_LEN ); 

  /**if ( length < 0 ) {
    perror( "read" );
  }  

 /* /*actually read return the list of change events happens. Here, read the change event one by one and process it accordingly.*/
 /* while ( i < length ) {     
  	
  	struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];     
  	if ( event->len ) {
     
        if ( event->mask & IN_MODIFY ) {
          printf( " %s MODIFIED.\n", event->name );
        }
      
      else if ( event->mask & IN_DELETE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "Directory %s deleted.\n", event->name );
        }
        
      }
    }
    i += EVENT_SIZE + event->len;
  }	*/

	
	
					
					/*strcpy(n_copy,"");
					strcat(n_copy, name);
					strcat(n_copy,"_rev");

					printf("%d\n",count );
					char m[999];
					sprintf(m, "%d", count);
					temp = m;
					strcat(n_copy,temp);
					current = n_copy;
					copy(name,current);
					count++;*/




























/*stat(name, &file_stat);
struct group* gr = getgrgid(file_stat.st_gid);
struct passwd* pw = getpwuid(file_stat.st_uid);*/


















  
  




}
