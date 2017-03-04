#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "unistd.h"
#include "HW_5_Part3.h"

int main(int argc, char* argv[])
{
	bool opt_a =false, opt_b = false, opt_d =false;
	int opt = getopt(argc, argv, "md:t");

	if(argv[1] = ""){
		printf("Usage: %sEXECUTABLE\n",argv[0]);

	}

  /while (opt != -1)
   {
      if (opt == 'p') {
         opt_p = true;
      } else if (opt == 'e') {
         opt_e = true;
      } else if (opt == 'u') {
         opt_u = true;
      }
      opt = getopt(argc, argv, "md:t");
   }






}