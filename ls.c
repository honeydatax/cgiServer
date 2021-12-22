#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("Content-type:plain-text\r\n\r\n\n\n\n");
	system ("ls -l");
	return 0;
}