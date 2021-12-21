#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char ss[80];
	char s[80];
	int n;
	int nn;
	time_t tt;
	tt=time(NULL);
	srand(tt);
	strcpy(ss," ");
	for(n=0;n<9;n++){
		nn=(char) rand()/5;
		sprintf(s," %d ",nn);
		strcat(ss,s);
	}
	printf("Content-type:plain-text\r\n\r\n");
	printf("\n%s\n",ss);
	return 0;
}