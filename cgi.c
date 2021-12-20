#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char a[1080];
	char b[1080];
	char c[1080];
	FILE * f;
	printf("\ec\e[44;36m\a\nstart server timer\n");
	system("python -m CGIHTTPServer 8080 &");
	sprintf(b,"timeout 15s curl http:/localhost:8080/control.txt > /tmp/out.txt 2> /dev/null");
	f=fopen("control.txt","w");
	strcpy(a,"01234567891012345678901234567890\n");
	fprintf(f,"%s\n",a);
	fclose (f);
	sleep(8);
	while(1){
		f=fopen("/tmp/out.txt","w");
		strcpy(a,"          \n");
		fprintf(f,"%s\n",a);
		fclose (f);
		system(b);
		f=fopen("/tmp/out.txt","r");
		strcpy(a,"          \0");
		fgets(a,10,f);
		fclose (f);
		a[9]=0;
		if (strcmp(a,"012345678\0")!=0){
			printf("\ec\e[44;36m\a\nrestart system\n");
			system("killall \"python\"");
			system("python -m CGIHTTPServer 8080 &");
		}
		
		sleep(30);
	}
	return 0;
}