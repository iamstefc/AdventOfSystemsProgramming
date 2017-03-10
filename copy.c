#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"
#include "printhelp.h"
#include "myFileCopy.h"
#include "watch.h"
#include "backup.h"

int main(int argc, char* argv[])
{  
	char* name = argv[1];
    if (argc != 2){
        return 0;
    } 
    if (stat(source, &pro) < 0){ 
        printf("Error sourcing");
        return 0;
    }
	
	bool opt_m =false, opt_d = false, opt_t =false;
	int opt = getopt(argc, argv, "md:t");

	if(argv[1] == ""){
		printf("Usage: %sEXECUTABLE\n",argv[0]);

	}
   copy(name);
	backup();
  watch(name);
 


  while (opt != -1)
   {
      if (opt == 'm') {
         opt_m = true;
      } else if (opt == 'd') {
         opt_d= true;
      } else if (opt == 't') {
         opt_t = true;
      }
      opt = getopt(argc, argv, "md:t");
   }
}
