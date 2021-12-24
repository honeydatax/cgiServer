#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

void *replacec(char *c){
	int n;
	int nn;
	char cc;
	nn=strlen(c);
	for(n=0;n<nn;n++){
		cc=c[n];
		if (cc=='_'){
			c[n]=' ';
		}
	}
}

int main(){
	FILE *f;
	char envi[1080];
	char *c;
	strcpy(envi,"QUERY_STRING");
	printf("Content-type:plain-text\r\n\r\n");
	c=getenv(envi);
	strcpy(envi,c);
	replacec(envi);
	f=fopen("/tmp/data.in","w");
	fprintf(f,"insert into dt (txt)values('%s');\n",envi);
	fprintf(f,"\n.quit\n");
	fclose(f);
	system("sqlite3 dd < /tmp/data.in");
	printf("%s\r\n",envi);
	return 0;
}