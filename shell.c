#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

void type_prompt() {
	printf("#");
}

void read_command(char cmd[], char *par[]) {
	char line[1024];
	int count = 0, i = 0, j = 0; 
	char *array[100], *pch;
	
	for(;;){
		int c = fgetc(stdin);
		line[count++] = (char)c;
		if (c == '\n') break;
	}
	if(count == 1) return;
	pch = strtok(line, " \n");
	
	while(pch != NULL) {
		array[i++] = strdup(pch);
		pch = strtok(NULL, " \n");
	}
	
	strcpy(cmd, array[0]);
	
	for(int j = 0; j < i; j++) {
		par[j] = array[j];
		par[i] = NULL;
	}
}

int main(int argc, char *argv[])  {  
  	char cmd[100], command[100], *parameters[20];
	while(1){
		type_prompt();
		read_command(command, parameters);
		if(strcmp(command, "exit") == 0){
			break;
		}
	}
	
	return 0;
}  