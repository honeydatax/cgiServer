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
	fprintf(f,"select * from dt ;\n");
	fprintf(f,"\n.quit\n");
	fclose(f);
	system("sqlite3 dd < /tmp/data.in > siteMap.txt");
	printf("%s\r\n",envi);
	f=fopen("siteMap.txt","r");
	if(f!=NULL){
		while(feof(f)!=1){
			fgets(envi,1024,f);
			printf("%s\n",envi);
		
		}
		fclose(f);
	}
	return 0;
}