#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"
#include "printhelp.h"
#include "myFileCopy.h"
#include "watch.h"

int main(int argc, char* argv[])
{  char* name = argv[1];
	bool opt_m =false, opt_d = false, opt_t =false;
	int opt = getopt(argc, argv, "md:t");

	if(argv[1] == ""){
		printf("Usage: %sEXECUTABLE\n",argv[0]);

	}
   copy(name);
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