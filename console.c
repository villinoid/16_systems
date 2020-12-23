#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int w,r,i;
	w=open("mario",O_WRONLY);
	r=open("luigi",O_RDONLY);
	char line[100];
	while(1){
		printf("enter line: ");
		fgets(line,sizeof(line),stdin);
		i=0;
		while(line[i]){
			i++;
		}
		line[i-1]=0;
		write(w,line,sizeof(line));
		read(r,line,sizeof(line));
		printf("%s\n",line);
	}
	return 0;
}