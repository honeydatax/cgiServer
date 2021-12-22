#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("Content-type:plain-text\r\n\r\n\r\n\r\n\r\n\r");
	system ("sudo ifconfig > ip.txt");
	printf("\r\n\r\n\r\n\r\n\r\n\r");
	return 0;
}