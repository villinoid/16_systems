#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


 
int main(){
	mkfifo("luigi",0644);
	mkfifo("mario",0644);
	int r,w,i;
	char line[100];
	r=open("mario",O_RDONLY);
	w=open("luigi",O_WRONLY);
	remove("./mario");
	remove("./luigi");
	while(1){
		read(r,line,sizeof(line));
		i=0;
		while(line[i]){
			line[i]=(line[i]-'a'+3)%23+'a';
			i++;
		}
		write(w,line,sizeof(line));
	}
	return 0;
}