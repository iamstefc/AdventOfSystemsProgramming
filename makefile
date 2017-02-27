copy: copy.c
	gcc -o copy copy.c
	
clean:
	rm copy
tar:
	tar -cf copy.tar copy.c makefile

