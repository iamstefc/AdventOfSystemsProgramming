#include <sys/inotify.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>


void watch(char* strFile)
{
	char st[100] ="";
	strcpy(st, strFile);
	int fd = inotify_init();
	int wd = inotify_add_watch(fd,st, IN_DELETE);
	ssize_t Event_Size = (sizeof(struct inotify_event));
	ssize_t buf_len = (1024 *(Event_Size +16));
    char buf[buf_len];
    char*i=NULL;
	
	while(1) {
		
		int x = read(fd, buf, buf_len);

		printf("%d",x);
		if(x == -1){
			printf("read fail\n");
			break;
		}

		for(char*p = buf; p < buf + x;) {
			struct inotify_event* event = (struct inotify_event*)p;
			if((event->mask&IN_DELETE) == IN_DELETE){
				printf("File was deleted\n");
				exit(0);
			}
			p += sizeof(struct inotify_event) + event->len;
		}
		
	}
}
	

