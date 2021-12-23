#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char envi[1080];
	char e[1080];
	char ss[80];
	char s[80];
	char *c;
	int n;
	int nn;
	FILE *f;
	time_t tt;
	tt=time(NULL);
	srand(tt);
		for(n=0;n<9;n++){
		nn=(char)((char) rand())/28;
		sprintf(s,"%d",nn);
		strcat(ss,s);
	}
	strcpy(envi,"QUERY_STRING");
	printf("Content-type:plain-text\r\n\r\n");
	c=getenv(envi);
	strcpy(envi,c);
	sprintf(e,"curl http://%s > /tmp/%s.c",envi,ss);
	system(e);
	sprintf(e,"gcc -o %s > /tmp/%s.c",ss,ss);
	system(e);
	printf("http:/localhost:8080/%s",ss);
	return 0;
}